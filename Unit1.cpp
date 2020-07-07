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
}
//---------------------------------------------------------------------------
