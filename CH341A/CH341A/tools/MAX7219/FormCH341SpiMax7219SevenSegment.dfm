object frmCH341SpiMax7219SevenSegment: TfrmCH341SpiMax7219SevenSegment
  Caption = 'MAX7219 8-digit seven-segment'
  ClientWidth = 450
  ClientHeight = 200
  Font.Name = 'Tahoma'
  Font.Height = -11
  PixelsPerInch = 96
  TextHeight = 13
  object lblDigits: TLabel
    Left = 16
    Top = 19
    Caption = '&Digits'
    FocusControl = editDigits
  end
  object editDigits: TEdit
    Left = 96
    Top = 16
    Width = 150
    Height = 21
    MaxLength = 8
    TabOrder = 0
    Text = '12345678'
  end
  object lblIntensity: TLabel
    Left = 16
    Top = 51
    Caption = '&Brightness'
    FocusControl = cbIntensity
  end
  object cbIntensity: TComboBox
    Left = 96
    Top = 48
    Width = 65
    Height = 21
    Style = csDropDownList
    TabOrder = 1
  end
  object chkReverse: TCheckBox
    Left = 16
    Top = 82
    Width = 180
    Height = 17
    Caption = '&Reverse digit order'
    TabOrder = 2
  end
  object btnWrite: TButton
    Left = 16
    Top = 112
    Width = 105
    Height = 25
    Caption = '&Write display'
    OnClick = btnWriteClick
    TabOrder = 3
  end
  object lblStatus: TLabel
    Left = 16
    Top = 152
    Caption = 'Digits and spaces are supported.'
  end
end
