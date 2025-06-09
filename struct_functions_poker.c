#include <stdio.h>

struct Poker {
    int value;  // 11 = Jack, 12 = Queen, 13 = King, 14 = Ace
    char suit;  // S = Spade, C = Club, H = Heart, D = Diamond
};

// Passing individual members
void setCard(struct Poker *card, int value, char suit) {
    card->value = value;
    card->suit = suit;
}

// Passing whole structure
int isSameSuit(struct Poker card1, struct Poker card2) {
    return card1.suit == card2.suit;
}

// Passing structure pointer
void countValue(int *valueCount, struct Poker *card) {
    valueCount[card->value]++;
}

// Passing array of structure
void inputCards(struct Poker cards[], int valueCount[]) {
    for (int i = 0; i < 5; i++) {
        int val;
        char suit;
        printf("Enter Card %d:\t", i + 1);
        scanf("%d %c", &val, &suit);
        setCard(&cards[i], val, suit);
        countValue(valueCount, &cards[i]);
    }
}

void sortValues(int values[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (values[i] > values[j]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

int checkStraight(int values[]) {
    for (int i = 0; i < 4; i++) {
        if (values[i] + 1 != values[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int checkFlush(struct Poker cards[]) {
    char suit = cards[0].suit;
    for (int i = 1; i < 5; i++) {
        if (cards[i].suit != suit) return 0;
    }
    return 1;
}

void analyzeHand(struct Poker cards[], int valueCount[]) {
    int values[5];
    for (int i = 0; i < 5; i++) values[i] = cards[i].value;
    sortValues(values);

    int isStraight = checkStraight(values);
    int isFlush = checkFlush(cards);

    int pairs = 0, threekind = 0, fourkind = 0;
    for (int i = 1; i <= 14; i++) {
        if (valueCount[i] == 2) pairs++;
        else if (valueCount[i] == 3) threekind++;
        else if (valueCount[i] == 4) fourkind++;
    }

    if (isStraight && isFlush) printf("Hand: Straight Flush\n");
    else if (fourkind == 1) printf("Hand: Four of a Kind\n");
    else if (threekind == 1 && pairs == 1) printf("Hand: Full House\n");
    else if (isFlush) printf("Hand: Flush\n");
    else if (isStraight) printf("Hand: Straight\n");
    else if (threekind == 1) printf("Hand: Three of a Kind\n");
    else if (pairs == 2) printf("Hand: Two Pairs\n");
    else if (pairs == 1) printf("Hand: One Pair\n");
    else printf("Hand: Nothing (no pair)\n");
}

int main() {
    struct Poker mycard[5];
    int again;

    printf("Values:\t2-10 = spot cards, 11 = Jack, 12 = Queen, 13 = King, 14 = Ace\n");
    printf("Suits:\tS = Spade, C = Club/Clover, H = Heart, D = Diamond\n");

    do {
        int valueCount[15] = {0};
        printf("\nPlease enter your 5 poker cards (ex: 4 C for 4 of clubs)\n");
        inputCards(mycard, valueCount);

        analyzeHand(mycard, valueCount);

        printf("Would you like to enter your cards again? 1 = Yes, 2 = No: ");
        scanf("%d", &again);
        if (again == 2) {
            printf("Are you sure to exit? 0 = exit, 2 = cancel: ");
            scanf("%d", &again);
        }
    } while (again > 0);

    return 0;
}
