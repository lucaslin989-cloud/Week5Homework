#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//TODO: Create an enumerator named "Suit." Set the values to be HEARTS, DIAMONDS,
//      CLUBS, and SPADES
enum Suit{HEART,DIAMONDS,CLUBS,SPADES
};

//TODO: Create a struct named "Card." It needs to have a variable of type int named 
//      value and a variable of type Suit named suit.
struct Card{
    int value;
    Suit suit;
};

//TODO: Create a function of type Card named getRandomCard(). It will not
//      have any parameters.
Card getRandomCard(){
//Within getRandomCard()....
    Card randomCard;
    //TODO: set the value variable within randomCard to be a random number between
    //      2 and 14
    randomCard.value=rand()%13+2;
    randomCard.suit = static_cast<Suit>(rand() % 4);
    return randomCard;
//End of getRandomCard()
}
//TODO: Create a function of type void named showCard(). It will take one parameter
//      of type Card named card.
//      Within the function, create a switch statement that will print
//      the card value depending on what random number was assigned to 
//      card.value.
//      For example: if card.value == 13 then cout << "| K "
//      Please be sure to print the statement exactly how I have it above.
//
//TODO: Still within the function, create a switch statement that will check the
//      value of card.suit. For example: If card.suit == HEARTS then
//      cout << "heart |" Remember to have the cout exactly as written
void showCard(Card card){
 switch (card.value){
    case 2: cout<<"| 2 ";break;
    case 3: cout<<"| 3 ";break;
    case 4: cout<<"| 4 ";break;
    case 5: cout<<"| 5 ";break;
    case 6: cout<<"| 6 ";break;
    case 7: cout<<"| 7 ";break;
    case 8: cout<<"| 8 ";break;
    case 9: cout<<"| 9 ";break;
    case 10: cout<<"| 10 ";break;
    case 11: cout<<"| J ";break;
    case 12: cout<<"| Q ";break;
    case 13: cout<<"| K ";break;
    case 14: cout<<"| A ";break;
 }
 switch(card.suit){
    case HEART:cout<<"heart |";break;
    case DIAMONDS:cout<<"diamonds |";break;
    case CLUBS:cout<<"clubs |";break;
    case SPADES:cout<<"spades |";break;
 }
}
//Because I am nice I have provided the next part ;)
void dealCardAndTotal(int& aceCount, int& total) {
    Card newCard = getRandomCard();
    showCard(newCard);
    if (newCard.value == 14) {
        total += 11;
    } else if (newCard.value >= 10) {
        total += 10;
    } else {
        total += newCard.value;
    }
    while (aceCount > 0 && total > 21) {
        aceCount--;
        total -= 10;
    }
}

//TODO: Create a function of type bool named hasBlackjack(). It takes 1 parameter
//      of type int named total.
//      If the total is equal to 21 then return true else false
bool hasBlackjack(int total){
    if (total==21){
        return true;
    }
    else{
        return false;
    }
}

//TODO: Create a function of type bool named hasBusted(). It takes 1 parameter
//      of type int named total.
//      If the total is greater than 21 then return true else false
bool hasBusted(int total){
    if (total>21){
        return true;
    }
    else{
        return false;
    }
}

void playBlackjack() {
    int playerTotal = 0;
    int dealerTotal = 0;
    int playerAceCount = 0;
    int dealerAceCount = 0;

    cout << "Your cards: ";
    //TODO: This is the user's hand. Deal them two cards
    //      by calling dealCardAndTotal() twice.
    dealCardAndTotal(playerAceCount, playerTotal);
    dealCardAndTotal(playerAceCount, playerTotal);

    cout << endl;

    cout << "Dealer's cards: ";
    cout << "? ";
    //TODO: This is the dealer's hand, so you will only be dealing 1 card right now
    dealCardAndTotal(dealerAceCount, dealerTotal);
    cout << endl;

    while (true) {
        //TODO: check to see if the player has a blackjack
        //      else check to see if the player busted
        hasBlackjack(playerTotal);
        hasBusted(playerTotal);
        cout << "Your total: " << playerTotal << endl;
        cout << "Do you want to hit (h) or stand (s)? ";
        char choice;
        cin >> choice;

        if (choice == 'h') {
            cout << "You drew a card: ";
            //TODO: Draw another card for the player
            dealCardAndTotal(playerAceCount, playerTotal);
            cout << endl;
        } else if (choice == 's') {
            cout << "You chose to stand.\n";
            break;
        } else {
            cout << "Invalid choice. Please enter 'h' to hit or 's' to stand.\n";
        }
    }

    if (!hasBlackjack(playerTotal) && !hasBusted(playerTotal)) {
        //TODO: reveal the dealer's second card (hint: draw a new card)
        //      After which print the dealer's total to the console
        dealCardAndTotal(dealerAceCount, dealerTotal);
        cout<<"Dealer's total: "<<dealerTotal<<endl;
        //TODO: If the dealer's total is less than 17 then deal a new card
        if(dealerTotal< 17){
            dealCardAndTotal(dealerAceCount, dealerTotal);
        }
        //TODO: Check to see if the user has a blackjack else check if they have
        //      busted
        hasBlackjack(dealerTotal);
        hasBusted(dealerTotal);

    }

    if ((playerTotal > dealerTotal && !hasBusted(playerTotal)) || hasBlackjack(playerTotal) || hasBusted(dealerTotal)) {
        cout << "You win!\n";
    } else if ((dealerTotal > playerTotal && !hasBusted(dealerTotal)) || hasBlackjack(dealerTotal) || hasBusted(playerTotal)) {
        cout << "Dealer wins!\n";
    } else {
        cout << "It's a tie!\n";
    }
}

int main() {
    srand(time(nullptr));
    playBlackjack();
    return 0;
}