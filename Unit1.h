//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tgameboard : public TForm
{
__published:	// IDE-managed Components
        TImage *paddleL;
        TImage *paddleR;
        TTimer *timerPaddleLUp;
        TTimer *timerPaddleLDown;
        TImage *ball;
        TTimer *timerBall;
        TTimer *timerPaddleRUp;
        TTimer *timerPaddleRDown;
        TImage *tlo;
        TButton *Button1;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        void __fastcall timerPaddleLUpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall timerPaddleLDownTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall timerBallTimer(TObject *Sender);
        void __fastcall timerPaddleRUpTimer(TObject *Sender);
        void __fastcall timerPaddleRDownTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tgameboard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tgameboard *gameboard;
//---------------------------------------------------------------------------
#endif
