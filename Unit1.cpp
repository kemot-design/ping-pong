//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int ballY = 10;
int ballX = 10;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerPaddleLUpTimer(TObject *Sender)
{
        if(paddleL->Top > 10) paddleL->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
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
void __fastcall TForm1::timerPaddleLDownTimer(TObject *Sender)
{
        if(paddleL->Top + paddleL->Height < tlo->Height - 10) paddleL->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
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
void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
        ball->Top += ballY;
        ball->Left += ballX;

        if(ball->Left <= tlo->Left + 10) ballX = -ballX;
        if(ball->Left + ball->Width >= tlo->Width - 10) ballX = -ballX;
        if(ball->Top <= 10) ballY = -ballY;
        if(ball->Top + ball->Height >= tlo->Height - 10) ballY = -ballY;

        if(ball->Left <= tlo->Left + 10){
                timerBall->Enabled = false;
                ball->Visible = false;
        }
        else if(ball->Top >= paddleL->Top - ball->Height/2 &&
        ball->Top <= paddleL->Top + paddleL->Height + ball->Height/2 &&
        ball->Left <= paddleL->Left + paddleL->Width){
                if(ballX < 0) ballX = -ballX;
        }

        if(ball->Left + ball->Width >= tlo->Width - 10){
                timerBall->Enabled = false;
                ball->Visible = false;
        }
        else if(ball->Top >= paddleR->Top - ball->Height/2 &&
        ball->Top <= paddleR->Top + paddleR->Height + ball->Height/2 &&
        ball->Left + ball->Width >= paddleR->Left){
                if(ballX > 0) ballX = -ballX;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerPaddleRUpTimer(TObject *Sender)
{
        if(paddleR->Top > 10) paddleR->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerPaddleRDownTimer(TObject *Sender)
{
        if(paddleR->Top + paddleR->Height < tlo->Height - 10) paddleR->Top += 10;
}
//---------------------------------------------------------------------------

