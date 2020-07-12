//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TgameMenu *gameMenu;
//---------------------------------------------------------------------------
__fastcall TgameMenu::TgameMenu(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TgameMenu::Button1Click(TObject *Sender)
{
        gameboard->Visible = true;
        gameMenu->Close();
}
//---------------------------------------------------------------------------
void __fastcall TgameMenu::Button2Click(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

