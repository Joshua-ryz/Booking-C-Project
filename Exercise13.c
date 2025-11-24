#include <stdio.h>
// Programmed by Rayne
// 
    /*
    1. Start
    2. ASK For room type 
        2.1 1: Standard ($1000/n)
        2.2 2: Deluxe ($2000/n)
        2.3 3: Suite (3500/n)
    3. ASK for number of nights 
    4. ASK for number of guest 
        if guest > 2, charge extrea $500 per additional gueast per night
    5. ASK if user want breakfast
        if yes, add 200 per guest per night
    6. ASK for membership type 
        6.1 1: Silver (.10%)
        6.2 2: Gold (.20%)
        6.3 3: Platinum (30% discount)
        6.4 4: None (No discount)
    7. ASK if today is weekend 
        if yes, add 0.05 weekend for surcharge on room price
    8. ASK for payment method 
        8.1 1: Cash (no fee)
        8.2 2: Credit Card (2% surchage)
    9. DISPLAY BILL
        9.1 Room type
        9.2 Night Stayed
        9.3 Guests 
        9.4 Subtotal
        9.5 Additional charges (extra guests, breakfast, weekend surcharge, card fee)
        9.6 Discounts 
        9.7 Final Total
    10. End
    */

int main () {
    int room_type;
    float room_price, subtotal = 0, discount = 0, surcharge = 0, extra_cost = 0;

    printf ("Welcome to Rayne's Hotel!\n");
    printf ("Please select room type (1: Standard = $1000) (2: Deluxe = $2000) (3: Suite = 3500): ");
    scanf ("%d", &room_type);
        switch (room_type) {
            case 1:
                room_price = 1000;
                break;
            case 2:
                room_price = 2000;
                break;
            case 3:
                room_price = 3500;
                break;
            default:
                printf ("Invalid Input!");
                return 0;
        }
    
    int stay;
    printf ("How many nights to stay?: ");
    scanf ("%d", &stay);

    subtotal = room_price * stay;

    int guests;
    printf ("How many guests: ");
    scanf ("%d", &guests);
        if (guests) {
            if (guests > 2) {
                extra_cost = (guests - 2) * 500 * stay;
            }
            else if (guests == 1) {

            }

            else if (guests < 0) {
                printf ("Invalid input!");
                return 0;
            }
        }

    int breakfast;
    printf ("Do you want any breakfast? (1: Yes 2: No): ");
    scanf ("%d", &breakfast);
        if (breakfast) {
            if (breakfast == 1) {
                extra_cost += guests * stay * 200;
            }
            else if (breakfast == 2) {
                
            }
            else {
                printf ("Invalid Input!");
                return 0;
            }
        }

    int membership;
    printf ("Enter membership (1: Silver) (2: Gold) (3: Platinum) (4: None): "); // silver = .10 gold = .20 pla = .30 4 = none
    scanf ("%d", &membership);
        switch (membership) {
            case 1: 
                discount += subtotal * 0.10;
                break;
            case 2: 
                discount += subtotal * 0.20;
                break;
            case 3:
                discount += subtotal * 0.30;
                break;
            case 4:
                discount = 0;
                break;
            default:
                printf ("Invalid input!");
                return 0;
        }
    
    int weekend; 
    printf ("Is it (1: weekend) (2: Weekdays): ");
    scanf ("%d", &weekend);
        if (weekend) {
            if (weekend == 1) {
                surcharge += subtotal * 0.05;
            }
            else if (weekend == 2) {
                discount = 0;
            }
            else {
                printf ("Invalid Input!");
                return 0;
            }
        }
    
    int payment;
    printf ("Enter payment (1: Cash) (2: Credit Card): ");
    scanf ("%d", &payment);
        if (payment) {
            if (payment == 1) {
                    surcharge = 0;
            }
            else if (payment == 2) {
                    surcharge += subtotal * 0.02;
            }
            else {
                printf ("Invalid Input!");
                return 0;
            }
        }

    float total;
    total = subtotal + extra_cost - discount + surcharge;

    printf ("Subtotal: %.2f\n", subtotal);
    printf ("Total: %.2f", total);
    return 0;
}