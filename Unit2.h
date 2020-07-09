//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TgameMenu : public TForm
{
__published:	// IDE-managed Components
        TShape *menuBackground;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TgameMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TgameMenu *gameMenu;
//---------------------------------------------------------------------------
#endif
