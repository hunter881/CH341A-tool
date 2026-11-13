#include <vcl.h>
#pragma hdrstop

#include "FormCH341SpiMax7219SevenSegment.h"
#include "MAX7219.h"
#include "CH341A.h"
#include "TabManager.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmCH341SpiMax7219SevenSegment *frmCH341SpiMax7219SevenSegment;

__fastcall TfrmCH341SpiMax7219SevenSegment::TfrmCH341SpiMax7219SevenSegment(TComponent *Owner)
    : TForm(Owner)
{
    for (int intensity = 0; intensity <= 15; ++intensity)
        cbIntensity->Items->Add(IntToStr(intensity));
    cbIntensity->ItemIndex = 1;
    TabManager::Instance().Register(this, 1u << ToolGroupDisplays);
}

void __fastcall TfrmCH341SpiMax7219SevenSegment::btnWriteClick(TObject *Sender)
{
    const AnsiString text = editDigits->Text;
    uint8_t digits[MAX7219::DIGITS];
    for (int i = 0; i < MAX7219::DIGITS; ++i)
    {
        const char digit = i < text.Length() ? text[i + 1] : ' ';
        if (digit != ' ' && (digit < '0' || digit > '9'))
        {
            lblStatus->Caption = "Enter up to eight digits. Spaces leave positions blank.";
            return;
        }
        const int position = chkReverse->Checked ? i : MAX7219::DIGITS - 1 - i;
        digits[position] = digit == ' ' ? 0x0F : static_cast<uint8_t>(digit - '0');
    }

    if (!ch341a.IsOpened())
    {
        lblStatus->Caption = "Open CH341A before writing.";
        return;
    }

    if (MAX7219::writeSevenSegment(digits, static_cast<uint8_t>(cbIntensity->ItemIndex)) != 0)
    {
        lblStatus->Caption = "SPI write failed. Check the adapter and retry.";
        return;
    }
    lblStatus->Caption = "SPI writes completed.";
}
