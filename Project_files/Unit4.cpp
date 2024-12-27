//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
char playerSymbol = 'x';
bool canPlay;

bool TForm2:: checkWinner() {
	if (!Button1->Text.IsEmpty() && Button1->Text == Button2->Text && Button1->Text == Button3->Text) {
		return true;
	}
	if (!Button4->Text.IsEmpty() && Button4->Text == Button5->Text && Button4->Text == Button6->Text) {
		return true;
	}
	if ((!Button7->Text.IsEmpty() && Button7->Text == Button8->Text) && (Button7->Text == Button9->Text) ) {
		return true;
	}
	if ((!Button1->Text.IsEmpty() && Button1->Text == Button4->Text) && (Button1->Text == Button7->Text) ) {
		return true;
	}
	if ((!Button2->Text.IsEmpty() && Button2->Text == Button5->Text) && (Button2->Text == Button8->Text) ) {
		return true;
	}
	if ((!Button3->Text.IsEmpty() && Button3->Text == Button6->Text) && (Button3->Text == Button9->Text) ) {
		return true;
	}
	if ((!Button1->Text.IsEmpty() && Button1->Text == Button5->Text) && (Button1->Text == Button9->Text) ) {
		return true;
	}
    if ((!Button3->Text.IsEmpty() && Button3->Text == Button5->Text) && (Button3->Text == Button7->Text) ) {
		return true;
	}
	return false;
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	currentPlayerSymbolLabel->Text = playerSymbol;
	canPlay = true;
}
void __fastcall TForm2::ButtonClick(TObject *Sender)
{   if (canPlay) {

		TButton* clickedButton = dynamic_cast<TButton*>(Sender);
		if (clickedButton->Text == 'x' || clickedButton->Text == 'o') {
            //Do nothing
		}
		else
		{
			clickedButton->Text = playerSymbol;
		}



        if (checkWinner() ) {
		Label3->Text = "Wow you win Player: ";
		Label2->Text = playerSymbol;
        canPlay = false;
		return;
		}

		if (playerSymbol == 'x') {
			playerSymbol = 'o';
		}
		else {
			playerSymbol = 'x';
		}
		currentPlayerSymbolLabel->Text = playerSymbol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button10Click(TObject *Sender)
{
	if(!canPlay) {
	//restart the game
	  canPlay = true;
	  Button1->Text = "";
	  Button2->Text = "";
	  Button3->Text = "";
	  Button4->Text = "";
	  Button5->Text = "";
	  Button6->Text = "";
	  Button7->Text = "";
	  Button8->Text = "";
	  Button9->Text = "";
      Label2->Text = "";
	}
}
//---------------------------------------------------------------------------

