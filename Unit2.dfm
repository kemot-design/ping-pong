object gameMenu: TgameMenu
  Left = 282
  Top = 199
  BorderStyle = bsToolWindow
  Caption = 'gameMenu'
  ClientHeight = 441
  ClientWidth = 912
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object menuBackground: TShape
    Left = 0
    Top = 0
    Width = 912
    Height = 441
    Align = alClient
    Brush.Color = clMoneyGreen
  end
  object Label1: TLabel
    Left = 264
    Top = 112
    Width = 383
    Height = 34
    Caption = 'Ping - Pong The Game'
    Color = clWhite
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'BankGothic Md BT'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Button1: TButton
    Left = 168
    Top = 232
    Width = 161
    Height = 73
    Caption = 'New game'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'BankGothic Md BT'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 584
    Top = 232
    Width = 161
    Height = 73
    Caption = 'Exit'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'BankGothic Md BT'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
end
