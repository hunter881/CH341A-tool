#ifndef FormCH341SpiMax7219SevenSegmentH
#define FormCH341SpiMax7219SevenSegmentH

#include <Forms.hpp>
#include <StdCtrls.hpp>

class TfrmCH341SpiMax7219SevenSegment : public TForm
{
__published:
    TLabel *lblDigits;
    TEdit *editDigits;
    TLabel *lblIntensity;
    TComboBox *cbIntensity;
    TCheckBox *chkReverse;
    TButton *btnWrite;
    TLabel *lblStatus;
    void __fastcall btnWriteClick(TObject *Sender);
public:
    __fastcall TfrmCH341SpiMax7219SevenSegment(TComponent *Owner);
};

extern PACKAGE TfrmCH341SpiMax7219SevenSegment *frmCH341SpiMax7219SevenSegment;

#endif
