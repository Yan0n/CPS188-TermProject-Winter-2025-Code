/*

UPDATE LOG: 3/26/2025

I did questions 1 and 2, and I got stuck on question 3.

It is a bit weird, I might do it later. if u wanna try,
check lines 98, and (28 - 34) and read the manual.

By the way, I feel like I did something wrong with the variables since there
are so many of them, they probably expected us to use pointers or arrays.

If any of you think you can optimize this code, please change it and make the changes apparent in the log.

The actual lab paper hasn't been started yet, however that can easily be done later "just by inputing
information from here and the GNUplot graphs and what not".

On a final note, some of the questions require GNUPLOT, (easily chtgptable later), so no need to focus
on those questions. (specifically Q5, 6, 8), with this, only Q3, 4, and 7 are needed on here.

- Hakim

----------------------------------------------------------------------------------

UPDATE LOG: 3/27/2025

----------------------------------------------------------------------------------



*/

/*
I will start the report and work on q4 i have an exmaple of my friends ill share it with u guys so u have an idea of the report

-Omer



*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double average(double sum, int size) { // This is used since there is an extensive need to calculate averages.
    return (sum / size);
}

int main() {


    // For question 3)

    int* yearHighest[7];
    int* dayHighest [7]; // these  variables will store the days and years of the highest ice concentration %.
    int iceConcentrationHighest[7];

    // ---------------------------



    // This code is to read the file

    // File parameters or columns (used when reading the file)
    int year, day; // Year and day
    double sup, mich, huron, erie, ont, stclr; // the great lakes
    double glTotal; // total for each day


    // 2023 DATA
    double supAvg23, michAvg23, huronAvg23, erieAvg23, ontAvg23, stclrAvg23; // average for each lake (2023)
    double glTotalAvg23; // average for the total (2023)

    int avgSize23; // average size for the total (2023)

    // 2024 DATA
    double supAvg24, michAvg24, huronAvg24, erieAvg24, ontAvg24, stclrAvg24; // average for each lake (2024)
    double glTotalAvg24; // average for the total (2024)

    int avgSize24; // average size for the total (2024)


    // INPUT (2021 - 2022 DATA) Q7)

    // INPUT (2022 - 2023 DATA) Q7)

    // INPUT (2023 - 2024 DATA)

    FILE* file;

    file  = fopen ("2023_2024_Lake_Data.dat", "r"); // This data can be found inside the folder of the project

    while (fscanf (file, "%d%d %lf%lf%lf%lf%lf%lf %lf", &year, &day, &sup, &mich, &huron, &erie, &ont, &stclr, &glTotal) != EOF)
    {

        /********* QUESTION 1 *********/

        // Cases to determine the data
        if (year == 2023) {
            supAvg23 += sup;
            michAvg23 += mich;
            huronAvg23 += huron;
            erieAvg23 += erie;
            ontAvg23 += ont;
            stclrAvg23 += stclr;
            glTotalAvg23 += glTotal;

            avgSize23++;
        }

        else if (year == 2024) {
            supAvg24 += sup;
            michAvg24 += mich;
            huronAvg24 += huron;
            erieAvg24 += erie;
            ontAvg24 += ont;
            stclrAvg24 += stclr;
            glTotalAvg24 += glTotal;

            avgSize24++;
        }
        /********* QUESTION 3 *********/



    }
    fclose (file);

    //
    // PROCESSING
    //

    // QUESTION 1) the 14 averages for each lake & total

    // Calculate the averages for 2023

    supAvg23 = average(supAvg23, avgSize23);
    michAvg23 = average(michAvg23, avgSize23);
    huronAvg23 = average(huronAvg23, avgSize23);
    erieAvg23 = average(erieAvg23, avgSize23);
    ontAvg23 = average(ontAvg23, avgSize23);
    stclrAvg23 = average(stclrAvg23, avgSize23);
    glTotalAvg23 = average(glTotalAvg23, avgSize23);

    // Calculate the averages for 2024

    supAvg24 = average(supAvg24, avgSize24);
    michAvg24 = average(michAvg24, avgSize24);
    huronAvg24 = average(huronAvg24, avgSize24);
    erieAvg24 = average(erieAvg24, avgSize24);
    ontAvg24 = average(ontAvg24, avgSize24);
    stclrAvg24 = average(stclrAvg24, avgSize24);
    glTotalAvg24 = average(glTotalAvg24, avgSize24);


    // QUESTION 2) highest and lowest ice concentration percentage based on average
    double lakeAvg[12] = {supAvg23, michAvg23, huronAvg23, erieAvg23, ontAvg23, stclrAvg23,
    supAvg24, michAvg24, huronAvg24, erieAvg24, ontAvg24, stclrAvg24};

    double lakeAvgMax = lakeAvg[0], lakeAvgMin = lakeAvg[0];

    int lakeAvgMaxIndex = 0;
    int lakeAvgMinIndex = 0;
    for (int i = 0; i < 12; i++) {
        if (lakeAvg[i] > lakeAvgMax){
            lakeAvgMax = lakeAvg[i];
            lakeAvgMaxIndex = i;
        }
        if (lakeAvg[i] < lakeAvgMin){
            lakeAvgMin = lakeAvg[i];
            lakeAvgMinIndex = i;
        }
    }




    //
    // OUTPUT
    //

    // OP QUESTION 1)

    // Print the averages for 2023
    printf("Averages for 2023:\n");
    printf("Lake Superior: %.2lf\n", supAvg23);
    printf("Lake Michigan: %.2lf\n", michAvg23);
    printf("Lake Huron: %.2lf\n", huronAvg23);
    printf("Lake Erie: %.2lf\n", erieAvg23);
    printf("Lake Ontario: %.2lf\n", ontAvg23);
    printf("Lake St. Clair: %.2lf\n", stclrAvg23);
    printf("Total Average for 2023: %.2lf\n", glTotalAvg23);
    // Print the averages for 2024
    printf("\nAverages for 2024:\n");
    printf("Lake Superior: %.2lf\n", supAvg24);
    printf("Lake Michigan: %.2lf\n", michAvg24);
    printf("Lake Huron: %.2lf\n", huronAvg24);
    printf("Lake Erie: %.2lf\n", erieAvg24);
    printf("Lake Ontario: %.2lf\n", ontAvg24);
    printf("Lake St. Clair: %.2lf\n", stclrAvg24);
    printf("Total Average for 2024: %.2lf\n", glTotalAvg24);

    // OP QUESTION 2)

    // Print the highest and lowest ice concentrations
    printf("\n Lake with the highest ice concentration is: Lake %d with an ice concentration (percent) of: %.2lf\n", lakeAvgMaxIndex, lakeAvgMax);

    printf("Lake with the lowest ice concentration is: Lake %d with an ice concentration (percent) of: %.2lf\n", lakeAvgMinIndex, lakeAvgMin);


    // OP QUESTION 3)


    return(0);
}