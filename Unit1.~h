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
    TImage *background;
    TButton *startBtn;
    TLabel *winnerLabel;
    TLabel *scoreLabel;
    TButton *nextRoundBtn;
    TButton *newGameBtn;
    TButton *exitBtn;
    TLabel *bouncesLabel;
    TLabel *gameTimeLabel;
    TImage *leftBlock;
    TTimer *blockLeftTimer;
    TImage *rightBlock;
    TTimer *leftBlockTimer;
    TTimer *rightBlockTimer;
        void __fastcall timerPaddleLUpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall timerPaddleLDownTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall timerBallTimer(TObject *Sender);
        void __fastcall timerPaddleRUpTimer(TObject *Sender);
        void __fastcall timerPaddleRDownTimer(TObject *Sender);
        void __fastcall startBtnClick(TObject *Sender);
    void __fastcall nextRoundBtnClick(TObject *Sender);
    void __fastcall newGameBtnClick(TObject *Sender);
    void __fastcall exitBtnClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall blockLeftTimerTimer(TObject *Sender);
    void __fastcall rightBlockTimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tgameboard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tgameboard *gameboard;
//---------------------------------------------------------------------------
#endif
