#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// Variables for the state machine control flow.
int curr_state = 0;						            // Number identifying  the current state of program (0 - loading of owner first name,
                                                    //                                                  1 - loading of owner surname,
                                                    //                                                  2 - loading animal name,
                                                    //                                                  3 - loading animal gender,
                                                    //                                                  4 - loading animal type,
                                                    //                                                  5 - loading animal age,
                                                    //                                                  6 - loading animal castration info,
                                                    //                                                  7 - loading animal accident info,
                                                    //                                                  8 - calculating insurance price,
                                                    //                                                  9 - printing out the results,
                                                    //                                                  10 - exiting).

                                                    // Customer name variables.
char owner_first_name[20];                          // The pet owner first name (maximal length is 20).
char owner_surname[20];                             // The pet owner surname (maximal length is 20).

                                                    // Customer's pets data variables.
char pet_names[10][20];                             // The pets names (maximal name length is 20; maximal number of pets is 10).
int pet_gender[10];                                 // The pets genders (0 - male,
                                                    //                   1 - female).
char pet_type[10];                                  // The pets types encoded as single characters ('D' - dog,
                                                    //                                              'C' - cat,
                                                    //                                              'B' - bird,
                                                    //                                              'R' - reptile).
float pet_type_price[5] = {50, 80, 40, 60, 10};     // The pets insurance prices                   ('0' - neutered dog,
                                                    //                                              '1' - not neutered dog
                                                    //                                              '2' - neutered cat,
                                                    //                                              '3' - not neutered cat,
                                                    //                                              '4' - bird or reptile.)
int pet_age[10];                                    // The pets ages.
int pet_is_neutered[10];                            // The pets castration data (0 - not neutered,
                                                    //                           1 - neutered).
int pet_had_accident[10];                           // The pets accident data (0 - did not have accident,
                                                    //                         1 - had accident).
float insurance_cost[10];                           // The array of insurance total costs.
float insurance_base_price[10];                     // The array of insurance base prices.
float insurance_mod_old[10];                        // The arrays of insurance modifiers.
float insurance_mod_young_male[10];                 //
float insurance_mod_accident[10];                   //
float quote;                                        // The final insurance quote.
int idx_curr_pet = 0;                               // The current index of processed pet (i.e. pet_gender[idx_curr_pet] is gender of currently added pet).

                                                    // Temporary use variables
char tmp[20];                                       // Any temporary variable that needs to be stored (i.e. integer inputs for the help menu).

int is_input_numeric()
{
    int i;
    for(i = 0; tmp[i] != '\0'; i++)
        if (tmp[i] > '9' || tmp[i] < '0')
            return 0;
    return 1;
}

void load_customer_first_name()
{
    system("cls");
    printf("Customer First Name:\n"); // Print the prompt for customer name.
    fflush(stdin);
    scanf("%s", owner_first_name); // Load the customer name using scanf().
    if (owner_first_name[0] == '?') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your first name");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, then switch current state to 1 (i.e. animal name loading) and return.
    {
        curr_state++; // Move to next state.
    }
}

void load_customer_surname()
{
    system("cls");
    printf("Customer Surname:\n"); // Print the prompt for customer name.
    fflush(stdin);
    scanf("%s", owner_surname); // Load the customer name using scanf().
    if (owner_surname[0] == '?') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your surname");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, then switch current state to 1 (i.e. animal name loading) and return.
    {
        curr_state++; // Move to next state.
    }
}

void load_animal_name()
{
    system("cls");
    printf("Animal Name:\n"); // Print out the prompt for animal name.
    fflush(stdin);
    scanf("%s", pet_names[idx_curr_pet]); // Load the info using scanf().
    if (pet_names[idx_curr_pet][0] == '?') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your pet's name");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, store it into data array.
    {
        curr_state++; // Move to next state.
    }
}

void load_animal_gender()
{
    system("cls");
    printf("Animal Gender:\n"); // Print out the prompt for animal gender.
    fflush(stdin);
    memset(tmp,'\0',20);
    scanf("%s", tmp); // Load the info using scanf().
    if ((tmp[0] == '0' || tmp[0] == '1') && tmp[1] == '\0')
    {
        if (tmp[0] == '?') // Print help, if user requires it and return.
        {
            printf("\nHelp: Please enter your pet's Gender");
            printf("\n      0=Male 1=Female");
            printf("\n      Press any key to continue");
            getch();
        }
        else // If user entered valid data, store it into data array.
        {
            pet_gender[idx_curr_pet] = atoi(tmp);
            curr_state++; // Move to next state.
        }
    }
    else
    {
        printf("\nError: That is an invalid input");
        printf("\n       Press any key to continue");
        getch();
    }
}

void load_animal_type()
{
    system("cls");
    printf("Animal Type:\n"); // Print out the prompt for animal type.
    fflush(stdin);
    scanf("%c", &pet_type[idx_curr_pet]); // Load the info using scanf().
    if (pet_type[idx_curr_pet] == '?') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your pet's name");
        printf("\n      Please enter D, C, B or R");
        printf("\n      (Dog, Cat, Bird or Reptile)");
        printf("\n      Press any key to continue");
        getch();
    }
    else if (pet_type[idx_curr_pet] != 'D' && pet_type[idx_curr_pet] != 'C' && pet_type[idx_curr_pet] != 'B' && pet_type[idx_curr_pet] != 'R')// If user entered invalid animal type, print out error and return. If user entered valid data, store it into data array.
    {
        printf("\nError: That is an invalid input");
        printf("\n       Please enter D, C, B or R");
        printf("\n       (Dog, Cat, Bird or Reptile)");
        printf("\n       Press any key to continue");
        getch();
    }
    else
    {
        curr_state++; // Move to next state.
    }
}

void load_animal_age()
{
    system("cls");
    printf("Animal Age:\n"); // Print out the prompt for animal age.
    fflush(stdin);
    memset(tmp,'\0',20);
    scanf("%s", tmp); // Load the info using scanf().
    if (tmp[0] == '?' && tmp[1] == '\0') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your pet's age");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, store it into data array.
    {
        if (is_input_numeric() == 1)
        {
            pet_age[idx_curr_pet] = atoi(tmp);
            curr_state++; // Move to next state.
        }
        else
        {
            printf("\nError: That is an invalid input");
            printf("\n       Press any key to continue");
            getch();
        }
    }
}

void load_animal_castration_info()
{
    system("cls");
    printf("Animal Castration Status:\n"); // Print out the prompt for animal castration info.
    fflush(stdin);
    memset(tmp,'\0',20);
    scanf("%s", tmp); // Load the info using scanf().
    if (tmp[0] == '?' && tmp[1] == '\0') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your pet's Castration Status");
        printf("\n      0=Not Neutered 1=Neutered");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, store it into data array.
    {
        if (is_input_numeric() == 1)
        {
            pet_is_neutered[idx_curr_pet] = atoi(tmp);
        curr_state++; // Move to next state.
        }
        else
        {
            printf("\nError: That is an invalid input");
            printf("\n       Press any key to continue");
            getch();
        }
    }
}

void load_animal_accident_info()
{
    system("cls");
    printf("Animal Accident Status:\n"); // Print out the prompt for animal accident info.
    fflush(stdin);
    memset(tmp,'\0',20);
    scanf("%s", tmp); // Load the info using scanf().
    if (tmp[0] == '?' && tmp[1] == '\0') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your pet's Accident Status");
        printf("\n      0=No Accident 1=Had Accident");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, store it into data array.
    {
        if (is_input_numeric() == 1)
        {
            pet_had_accident[idx_curr_pet] = atoi(tmp);
            curr_state++; // Move to next state.
        }
        else
        {
            printf("\nError: That is an invalid input");
            printf("\n       Press any key to continue");
            getch();
        }
    }
}

void calculate_animal_insurance() // Calculate the insurance fee, store it into data array and print out the insurance info.
{
    system("cls");
    switch (pet_type[idx_curr_pet])
    {
    case 'D':
        if (pet_is_neutered[idx_curr_pet] == 1)
        {
            insurance_cost[idx_curr_pet] = pet_type_price[0];
            insurance_base_price[idx_curr_pet] = pet_type_price[0];
        }
        else
        {
            insurance_cost[idx_curr_pet] = pet_type_price[1];
            insurance_base_price[idx_curr_pet] = pet_type_price[1];
        }
        break;
    case 'C':
        if (pet_is_neutered[idx_curr_pet] == 1)
        {
            insurance_cost[idx_curr_pet] = pet_type_price[2];
            insurance_base_price[idx_curr_pet] = pet_type_price[2];
        }
        else
        {
            insurance_cost[idx_curr_pet] = pet_type_price[3];
            insurance_base_price[idx_curr_pet] = pet_type_price[3];
        }
        break;
    case 'B':
    case 'R':
        insurance_cost[idx_curr_pet] = pet_type_price[4];
        insurance_base_price[idx_curr_pet] = pet_type_price[4];
        break;
    }
    if (pet_age[idx_curr_pet] > 5)
    {
        int i;
        for (i = 0, insurance_mod_old[idx_curr_pet] = 0; i < pet_age[idx_curr_pet] - 5; i++)
            insurance_mod_old[idx_curr_pet] += (insurance_cost[idx_curr_pet] + insurance_mod_old[idx_curr_pet]) * 0.02;
        insurance_cost[idx_curr_pet] += insurance_mod_old[idx_curr_pet];
    }
    else if (pet_age[idx_curr_pet] < 2 && pet_gender[idx_curr_pet] == 0)
    {
        insurance_mod_young_male[idx_curr_pet] = insurance_cost[idx_curr_pet] * 0.05;
        insurance_cost[idx_curr_pet] += insurance_mod_young_male[idx_curr_pet];
    }
    if (pet_had_accident[idx_curr_pet] == 1)
    {
        insurance_mod_accident[idx_curr_pet] = insurance_cost[idx_curr_pet] * 0.05;
        insurance_cost[idx_curr_pet] += insurance_mod_accident[idx_curr_pet];
    }
    printf("Insurance cost:\n");
    printf("%c%.2f", 156, insurance_cost[idx_curr_pet]);
    getch();
    curr_state++; // Move to next state.
}

void check_continue()
{
    system("cls");
    printf("Would you like to add an additional animal?\n"); // Ask user, if they want to add extra animal.
    memset(tmp,'\0',20);
    scanf("%c", tmp); // Load user input using scanf().
    if (tmp[0] == '?') // Print help, if user requires it and return.
    {
        printf("\nHelp: Add an additional animal? Y/N");
        printf("\n      Press any key to continue");
        getch();
    }
    else if (tmp[0] == 'N')// If user does not require to add more animals, switch current state to o 7 (i.e. result printing) and return.
    {
        curr_state++;
    }
    else if (tmp[0] == 'Y')
    {
        if (idx_curr_pet == 9) // If the maximal number of animals per owner would be exceeded, print error message and switch to next (i.e. result printing).
        {
            system("cls");
            printf("Adding another animal would exceed the limit.");
            printf("\nPress any key to continue to the print page");
            getch();
            curr_state++;
        }
        else // Otherwise increase index of current animal and switch state to 2 (i.e. animal name loading) and return.
        {
            idx_curr_pet++;
            curr_state = 2;
        }
    }
}

void print_result()
{
    system("cls");
    printf("%s %s - %d animal(s)", owner_first_name, owner_surname, idx_curr_pet+1);
    int i;
    for (i = 0; i <= idx_curr_pet; i++) // Iterate over data arrays.
    {
        printf("\n\n%s - %c%.2f", pet_names[i], 156, insurance_base_price[i]); // Print out all necessary information, including the base prices and insurance modifiers.
        if (insurance_mod_old[i] > 0) // If insurance modifier is set to 0, it can be ignored, since it was not used.
        {
            printf("\n(Age > 5: +%c%.2f)", 156, insurance_mod_old[i]);
        }
        if (insurance_mod_young_male[i] > 0)
        {
            printf("\n(Male Age < 2: +%c%.2f)", 156, insurance_mod_young_male[i]);
        }
        if (insurance_mod_accident[i] > 0)
        {
            printf("\n(Recent Accident: +%c%.2f)", 156, insurance_mod_accident[i]);
        }
        printf("\nSubtotal: %c%.2f", 156, insurance_cost[i]);
        quote += insurance_cost[i]; // Calculate the total insurance price.
    }
    printf("\n\nTotal: %c%.2f", 156, quote);
    getch();
    curr_state++; // Switch state to next and return.
}

int main(int argc, const char **argv)
{
    system("color F9");
    // Initialize data arrays.
    owner_first_name[0] = '\0';  // Empty string.
    owner_surname[0] = '\0';   // Empty string.
    int i;
    for (i = 0; i < 10; i++)
    {
        pet_names[i][0] = '\0';          // Empty string.
        pet_gender[i] = -1;              // -1 as not set.
        pet_type[i] = 'U';               // 'U' as undefined type.
        pet_age[i] = -1;                 // -1 as not set.
        pet_is_neutered[i] = -1;         // -1 as not set.
        pet_had_accident[i] = -1;        // -1 as not set.
        insurance_cost[i] = 0;           // 0 as not set.
        insurance_base_price[i] = 0;     // 0 as not set.
        insurance_mod_old[i] = 0;        // 0 as not set.
        insurance_mod_young_male[i] = 0; // 0 as not set.
        insurance_mod_accident[i] = 0;   // 0 as not set.
    }

    // Run indefinitely, until program reaches the state / (i.e. the termination state).
    while (curr_state != 11)
    {
        // Check the current state so we can do stuff according to it.
        switch (curr_state)
        {
        // The initial state, where customer name is loaded.
        case 0:
            load_customer_first_name();
            break;

        // The initial state, where customer name is loaded.
        case 1:
            load_customer_surname();
            break;

        // The state, in which the animal name is loaded.
        case 2:
            load_animal_name();
            break;

        // The state, in which the animal gender is loaded.
        case 3:
            load_animal_gender();
            break;

        // The state, in which the animal type is loaded.
        case 4:
            load_animal_type();
            break;

        // The state, in which the animal age is loaded.
        case 5:
            load_animal_age();
            break;

        // The state, in which the animal castration info is loaded.
        case 6:
            load_animal_castration_info();
            system("cls");
            break;

        // The state, in which the animal accident info is loaded.
        case 7:
            load_animal_accident_info();
            break;

        // The state, in which the animal insurance price is calculated.
        case 8:
            calculate_animal_insurance();
            break;

        // The state for deciding, if user wants to continue with adding more animals.
        case 9:
            check_continue();
            break;

        // The state for printing the insurance result.
        case 10:
            print_result();
            break;
        }
    }
    return 0; // Terminate gracefully.
}
