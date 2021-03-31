// Preprocessor Directive
#include <iostream>
#include <ctime>

int LevelDifficulty = 1;
int MaxDifficulty = 6;
int UsedValues [3] = {0, 0, 0};

void PrintIntro()
{
    // Print Welcome messages to terminal
    std::cout << "\n\n\"Here is the level : " << LevelDifficulty << "\"\n\n";
}

int GenCodeValue()
{    
    int RetV = (rand() % (LevelDifficulty *2)) + 1;
    
    return RetV;
}

bool PlayGame()
{   
    PrintIntro();
    
    // Declare 3 Number Code
    int CodeA = GenCodeValue();
    int CodeB = GenCodeValue();
    int CodeC = GenCodeValue();
    
    /* Debug
    std::cout << "\n*** A = " << CodeA << " | B = " << CodeB << " | C = " << CodeC << " ***";
    */
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print Sum & Product to the terminal
    std::cout << "\"+ There are 3 numbers in the code\"";
    std::cout << "\n\"+ The codes add-up to: " << CodeSum << "\"";
    std::cout << "\n\"+ The code multiply to give: " << CodeProduct << "\"";

    int GuessA, GuessB, GuessC;

    std::cout << "\nWhat will your answer be, adventurer?\n";
    std::cin >> GuessA >> GuessB >> GuessC;
    
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n\"Congratulations! You might not be as dumb as you look ! Now let's try a harder question!\"";
        return true;
    }
    else
    {        
        std::cout << "\n\"Ha! I knew you weren the sharpest tool in the shed the moment I layed my eyes on you!\"";
        return false;
    }    
}

int main()
{
    srand(time(NULL));

    //First Time Only message to the player
    std::cout << "\n\n\"Adventurer! Here you are shall be tested on your intelligence an logic abilities!\" ,said the magician. \n";
    std::cout << "\"Rise to this challenges until you cannot find the answer, my guess is it'll happen sooner rather than later...\" \n\n";


    bool IsAnswerRight = true;

    while (LevelDifficulty <= MaxDifficulty && IsAnswerRight)
    {
        IsAnswerRight = PlayGame();
        std::cin.clear() ;
        std::cin.ignore();

        if (IsAnswerRight)
        {
            ++LevelDifficulty;
        }
    } 

    if (LevelDifficulty >= MaxDifficulty)
    {
        std::cout << "\n\n\"Congratulation adventurer, you completed all the challenges I had for you, you're brighter in the inside than you appear !\", said the magician with visible surprise and frustration ... You can know continue your quest !";
    }
    
    

    // Main function return value
    return 0;
}
