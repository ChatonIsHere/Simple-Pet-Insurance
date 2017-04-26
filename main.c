#include <stdio.h>
#include <stdlib.h>

// Variables for the state machine control flow.
int curr_state = 0;						            // Numer identifying  the current state of program (0 - loading of owner name,
                                                    //                                                  1 - loading animal name,
                                                    //                                                  2 - loading animal gender,
                                                    //                                                  3 - loading animal type,
                                                    //                                                  4 - loading animal castration info,
                                                    //                                                  5 - loading animal accident info,
                                                    //                                                  6 - asking if another animal should be added,
                                                    //                                                  7 - printing out the results,
                                                    //                                                  8 - exiting).

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
int pet_age[10];                                    // The pets ages.
int pet_is_neutered[10];                            // The pets castration data (0 - not neutered,
                                                    //                           1 - neutered).
int pet_had_accident[10];                           // The pets accident data (0 - did not have accident,
                                                    //                         1 - had accident).
int insurance_cost[10];                             // The array of insurance costs.
int idx_curr_pet = 0;                               // The current index of processed pet (i.e. pet_gender[idx_curr_pet] is gender of currently added pet).

// Temporary use variables
char tmp[20];                                       // Any temporary variable that needs to be stored (i.e. integer inputs for the help menu).

void load_customer_first_name()
{
    system("cls");
    printf("\Customer First Name:\n"); // Print the prompt for customer name.
    scanf("%s", owner_first_name); // Load the customer name using scanf().
    if (owner_first_name[0] == '?') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your first name");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, then switch current state to 1 (i.e. animal name loading) and return.
    {
        curr_state++;
    }
}

void load_customer_surname()
{
    system("cls");
    printf("\Customer Surname:\n"); // Print the prompt for customer name.
    scanf("%s", owner_surname); // Load the customer name using scanf().
    if (owner_surname[0] == '?') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your surname");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, then switch current state to 1 (i.e. animal name loading) and return.
    {
        curr_state++;
    }
}

void load_animal_name()
{
    system("cls");
    printf("\Animal Name:\n"); // Print out the prompt for animal name.
    scanf("%s", pet_names[idx_curr_pet]); // Load the info using scanf().
    if (pet_names[idx_curr_pet][0] == '?') // Print help, if user requires it and return.
    {
        printf("\nHelp: Please enter your pet's name");
        printf("\n      Press any key to continue");
        getch();
    }
    else // If user entered valid data, store it into data array.
    {
        curr_state++; // Switch current state to 2 (i.e. animal gender loading) and return.
    }
}

void load_animal_gender()
{
    system("cls");
    printf("\Animal Gender:\n"); // Print out the prompt for animal gender.
    scanf("%s", tmp); // Load the info using scanf().
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
        curr_state++; // Switch current state to 3 (i.e. animal type loading) and return.
    }
}

void load_animal_type()
{
    // Print out the prompt for animal type.
    // Load the info using scanf().
    // Print help, if user requires it and return.
    // If user entered invalid animal type, print out error and return.
    // If user entered valid data, store it into data array.
    // Switch current state to 4 (i.e. animal castration info loading) and return.
}

void load_animal_castration_info()
{
    // Print out the prompt for animal castration info.
    // Load the info using scanf().
    // Print help, if user requires it.
    // If user entered valid data, store it into data array.
    // Switch current state to 5 (i.e. animal accident info loading) and return.
}

void load_animal_accident_info()
{
    // Print out the prompt for animal accident info.
    // Load the info using scanf().
    // Print help, if user requires it and return.
    // If user entered valid data, store it into data array.
    // Calculate the insurance fee, store it into data array and print out the insurance info)
    // Switch current state to 6 (i.e. continue checking) and return.
}

void check_continue()
{
    // Ask user, if they want to add extra animal.
    // Load user input using scanf().
    // Print help, if user requires it and return.
    // If user does not require to add more animals, switch current state to o 7 (i.e. result printing) and return.
    // If the maximal number of animals per owner would be exceeded, print error message and switch to 7 (i.e. result printing).
    // Otherwise increase index of current animal and switch state to 1 (i.e. animal name loading) and return.
}

void print_result()
{
    // Iterate over data arrays.
    // Calculate the total insurance price.
    // Print out all necessary information.
    // Switch state to 8 and return.
}

int main(int argc, const char **argv)
{
    // Initialize data arrays.
    owner_first_name[0] = '\0';  // Empty string.
    owner_surname[0] = '\0';   // Empty string.
    int i;
    for (i = 0; i < 10; i++)
    {
        pet_names[i][0] = '\0';     // Empty string.
        pet_gender[i] = -1;         // -1 as not set.
        pet_type[i] = 'U';          // 'U' as undefined type.
        pet_age[i] = -1;            // -1 as not set.
        pet_is_neutered[i] = -1;    // -1 as not set.
        pet_had_accident[i] = -1;   // -1 as not set.
        insurance_cost[i] = -1;     // -1 as not set.
    }

    // Run indefinitely, until program reaches the state / (i.e. the termination state).
    while (curr_state != 8)
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

            // The state, in which the animal castration info is loaded.
            case 5:
                load_animal_castration_info();system("cls");
                break;

            // The state, in which the animal accident info is loaded.
            case 6:
                load_animal_accident_info();
                break;

            // The state for deciding, if user wants to continue
            // with adding more animals.
            case 7:
                check_continue();
                break;

            // The state for printing the insurance result.
            case 8:
                print_result();
                break;
        }
    }

    // Terminate gracefully.
	return 0;
}
