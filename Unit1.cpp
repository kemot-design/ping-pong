//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mmsystem.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgameboard *gameboard;

int ballXMove = 10;
int ballYMove = 5;
int regularBallXMove = 10;
int regularBallYMove = 5;
int leftPlayerPoints = 0;
int rightPlayerPoints = 0;
int bounces = 0;
int gameTime = 0;

void centerLabels(){
    gameboard->startBtn->Left = gameboard->background->Width / 2 - gameboard->startBtn->Width / 2;
    gameboard->winnerLabel->Left = gameboard->background->Width / 2 - gameboard->winnerLabel->Width / 2;
    gameboard->scoreLabel->Left = gameboard->background->Width / 2 - gameboard->scoreLabel->Width / 2;
    gameboard->bouncesLabel->Left = gameboard->background->Width / 2 - gameboard->bouncesLabel->Width / 2;
    gameboard->gameTimeLabel->Left = gameboard->background->Width / 2 - gameboard->gameTimeLabel->Width / 2;
    gameboard->newGameBtn->Left = gameboard->background->Width / 2 - gameboard->newGameBtn->Width / 2;
    gameboard->nextRoundBtn->Left = gameboard->background->Width / 2 - 350;
    gameboard->exitBtn->Left = gameboard->background->Width / 2 + 175;

}

void prepareFormToPlay(){
    gameboard->ball->Visible = true;
    gameboard->startBtn->Visible = true;
    gameboard->nextRoundBtn->Visible = false;
    gameboard->newGameBtn->Visible = false;
    gameboard->exitBtn->Visible = false;
    gameboard->gameTimeLabel->Visible = true;
    gameboard->winnerLabel->Visible = false;
    gameboard->scoreLabel->Visible = false;
    gameboard->bouncesLabel->Visible = false;
    gameTime = 0;
    bounces = 0;

}

void prepareFormAfterRound(AnsiString winner){
    gameboard->winnerLabel->Visible = true;
    gameboard->winnerLabel->Caption = winner + " player has won the round >>";
    gameboard->scoreLabel->Visible = true;
    gameboard->scoreLabel->Caption = "Score: " + IntToStr(leftPlayerPoints) + " - " + IntToStr(rightPlayerPoints);
    gameboard->bouncesLabel->Visible = true;
    gameboard->bouncesLabel->Caption = "Bounces: " + IntToStr(bounces);
    gameboard->nextRoundBtn->Visible = true;
    gameboard->newGameBtn->Visible = true;
    gameboard->exitBtn->Visible = true;
    centerLabels();

}

//---------------------------------------------------------------------------
__fastcall Tgameboard::Tgameboard(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::timerPaddleLUpTimer(TObject *Sender)
{
        if(paddleL->Top > 10) paddleL->Top -= 8;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::timerPaddleLDownTimer(TObject *Sender)
{
        if(paddleL->Top + paddleL->Height < background->Height - 10) paddleL->Top += 8;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::timerPaddleRUpTimer(TObject *Sender)
{
        if(paddleR->Top > 10) paddleR->Top -= 8;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::timerPaddleRDownTimer(TObject *Sender)
{
        if(paddleR->Top + paddleR->Height < background->Height - 10) paddleR->Top += 8;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

         if((Key == 'A') || (Key == 'a')){
                timerPaddleLUp->Enabled = true;
         }
          if((Key == 'Z') || (Key == 'z')){
                timerPaddleLDown->Enabled = true;
         }

         if(Key == VK_UP){
                timerPaddleRUp->Enabled = true;
         }
         if(Key == VK_DOWN){
                timerPaddleRDown->Enabled = true;
         }

}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
         if((Key == 'A') || (Key == 'a')){
                timerPaddleLUp->Enabled = false;
         }
          if((Key == 'Z') || (Key == 'z')){
                timerPaddleLDown->Enabled = false;
         }

         if(Key == VK_UP){
                timerPaddleRUp->Enabled = false;
         }
          if(Key == VK_DOWN){
                timerPaddleRDown->Enabled = false;
         }
}
//---------------------------------------------------------------------------
void __fastcall Tgameboard::timerBallTimer(TObject *Sender)
{
        if(gameTime > 0 && gameTime % 500 == 0){
            regularBallXMove *= 1.5;
            regularBallYMove *= 1.5;
        }

        //bounce top
        if(ball->Top <= 10){
            ballYMove = regularBallYMove;
        }

        // bounce botton
        else if(ball->Top + ball->Height >= background->Height - 10){
           ballYMove = -regularBallYMove;
        }

        //left paddle bounce or fail
        if(ball->Left < paddleL->Left - 10){
                timerBall->Enabled = false;
                ball->Visible = false;
                rightPlayerPoints++;
                prepareFormAfterRound("Right");
        }
        else if(ball->Top >= paddleL->Top - (ball->Height/2) &&
                ball->Top <= paddleL->Top + paddleL->Height - (ball->Height/2) &&
                ball->Left <= paddleL->Left + paddleL->Width){

                if(ball->Top > paddleL->Top + 25 &&
                ball->Top < paddleL->Top + paddleL->Height - 65){
                        ballXMove = -regularBallXMove * 2;
                        sndPlaySound("snd/Ricochet.wav", SND_ASYNC);
                }
                else {
                        ballXMove = -regularBallXMove;
                        if(ballYMove > 0) ballYMove = regularBallYMove;
                        else ballYMove = -regularBallYMove;
                        sndPlaySound("snd/BallBounce.wav", SND_ASYNC);
                }

                ballXMove = -ballXMove;
                bounces++;
        }

        //right paddle bounce or fail
        if(ball->Left + ball->Width >= background->Width + 10){
                timerBall->Enabled = false;
                ball->Visible = false;
                leftPlayerPoints++;
                prepareFormAfterRound("Left");
        }
        else if(ball->Top >= paddleR->Top - (ball->Height/2) &&
                ball->Top <= paddleR->Top + paddleR->Height - ball->Height/2 &&
                ball->Left + ball->Width >= paddleR->Left){

                if(ball->Top >= paddleR->Top + 25 &&
                ball->Top <= paddleR->Top + paddleR->Height - 65){
                        ballXMove = regularBallXMove * 2;
                        sndPlaySound("snd/Ricochet.wav", SND_ASYNC);
                }
                else {
                        ballXMove = regularBallXMove;
                        if(ballYMove > 0) ballYMove = regularBallYMove;
                        else ballYMove = -regularBallYMove;
                        sndPlaySound("snd/BallBounce.wav", SND_ASYNC);
                }

                ballXMove = -ballXMove;
                bounces++;
        }


        ball->Top += ballYMove;
        ball->Left += ballXMove;
        gameTime++;

        gameTimeLabel->Caption = "Game time: " + IntToStr(gameTime/50) + " sec.";
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::startBtnClick(TObject *Sender)
{
        timerBall->Enabled = true;
        startBtn->Visible = false;
        regularBallXMove = 10;
        regularBallYMove = 5;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::nextRoundBtnClick(TObject *Sender)
{
    ball->Top = rand() % 330 + 100;
    ball->Left = rand() % 150 + 450;
    prepareFormToPlay();
    if(ballXMove > 0) ballXMove = -10;
    else ballXMove = 10;

}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::newGameBtnClick(TObject *Sender)
{
    leftPlayerPoints = 0;
    rightPlayerPoints = 0;
    ball->Top = rand() % 330 + 100;
    ball->Left = rand() % 150 + 450;
    prepareFormToPlay();

    ballXMove = regularBallXMove;
    ballYMove = regularBallYMove;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::exitBtnClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::FormCreate(TObject *Sender)
{
    ball->Top = rand() % 330 + 100;
    ball->Left = rand() % 150 + 450;
}
//---------------------------------------------------------------------------

