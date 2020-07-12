//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

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


//---------------------------------------------------------------------------
__fastcall Tgameboard::Tgameboard(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::timerPaddleLUpTimer(TObject *Sender)
{
        if(paddleL->Top > 10) paddleL->Top -= 10;
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
void __fastcall Tgameboard::timerPaddleLDownTimer(TObject *Sender)
{
        if(paddleL->Top + paddleL->Height < tlo->Height - 10) paddleL->Top += 10;
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

        if((ball->Top <= 10) || (ball->Top + ball->Height >= tlo->Height - 10)){
           ballYMove = -ballYMove;
        }

        if(ball->Left <= tlo->Left - ball->Width){
                timerBall->Enabled = false;
                ball->Visible = false;
                rightPlayerPoints++;

                Label1->Visible = true;
                Label1->Caption = "Right player has won the round >>";
                Label2->Visible = true;
                Label2->Caption = "Score: " + IntToStr(leftPlayerPoints) + " - " + IntToStr(rightPlayerPoints);
                Button2->Visible = true;
                Button3->Visible = true;
                Button4->Visible = true;
        }
        else if(ball->Top >= paddleL->Top - ball->Height/2 &&
                ball->Top <= paddleL->Top + paddleL->Height + ball->Height/2 &&
                ball->Left <= paddleL->Left + paddleL->Width){

                if(ball->Top >= paddleL->Top && ball->Top <= paddleL->Top + paddleL->Height ){
                        ballXMove = -regularBallXMove * 3;
                }
                else {
                        ballXMove = -regularBallXMove;
                }

                ballXMove = -ballXMove;
        }

        if(ball->Left >= tlo->Width){
                timerBall->Enabled = false;
                ball->Visible = false;
                leftPlayerPoints++;

                Label1->Visible = true;
                Label1->Caption = "<< Left player has won the round";
                Label2->Visible = true;
                Label2->Caption = "Score: " + IntToStr(leftPlayerPoints) + " - " + IntToStr(rightPlayerPoints);
                Button2->Visible = true;
                Button3->Visible = true;
                Button4->Visible = true;
        }
        else if(ball->Top >= paddleR->Top - ball->Height/2 &&
                ball->Top <= paddleR->Top + paddleR->Height + ball->Height/2 &&
                ball->Left + ball->Width >= paddleR->Left){
                   ballXMove = -regularBallXMove;
        }

        ball->Top += ballYMove;
        ball->Left += ballXMove;
}
//---------------------------------------------------------------------------
void __fastcall Tgameboard::timerPaddleRUpTimer(TObject *Sender)
{
        if(paddleR->Top > 10) paddleR->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::timerPaddleRDownTimer(TObject *Sender)
{
        if(paddleR->Top + paddleR->Height < tlo->Height - 10) paddleR->Top += 10;
}
//---------------------------------------------------------------------------


void __fastcall Tgameboard::Button1Click(TObject *Sender)
{
        timerBall->Enabled = true;
        Button1->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall Tgameboard::Button2Click(TObject *Sender)
{
    ball->Top = 200;
    ball->Left = 400;
    ballXMove = regularBallXMove;
    ballYMove = regularBallYMove;
    ball->Visible = true;
    Button1->Visible = true;
    Button2->Visible = false;
    Button3->Visible = false;
    Button4->Visible = false;
    Label1->Visible = false;
    Label2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::Button3Click(TObject *Sender)
{
    leftPlayerPoints = 0;
    rightPlayerPoints = 0;
    ball->Top = 200;
    ball->Left = 400;
    ballXMove = regularBallXMove;
    ballYMove = regularBallYMove;
    ball->Visible = true;
    Button1->Visible = true;
    Button2->Visible = false;
    Button3->Visible = false;
    Button4->Visible = false;
    Label1->Visible = false;
    Label2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall Tgameboard::Button4Click(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

