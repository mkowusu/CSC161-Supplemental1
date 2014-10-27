/*****************************************************************
     * Michael Owusu                                                 *
     * Box:  4271                                                    *
     * Supplemental Problem 1 for CSC 161                            *
     * Assignment for Friday, February 7                             *
     *****************************************************************/

    /* ***************************************************************
     * Academic honesty certification:                               *
     *   Help obtained                                               *
     *    I talked to Mr. Walker about errors I had while running    *
     *    my program in terminal and on emacs 
           I also consulted the textbooks and mentors with help on
           syntax and how to properly use C                          *
     *   My signature below confirms that the above list of sources  *
     *   is complete AND that I have not talked to anyone else       *
     *   [e.g., CSC 161 students] about the solution to this problem *
     *                                                               *
     *   Signature:                                                  *
     *****************************************************************/

/* This program computes the parking fee charged for a car parked in the parking lot identified in supplement problem #1. */

#include <stdio.h>                       /* reference to standard I/O library */


/* Preconditions: The user must enter in their time that they parked their car and when they picked it up rounded to the nearest minute. The hours must be entered in the correct spot, and so must the minutes. */


/* Postconditions: The user will be returned a final value, total price, that is the calculation of the time they spent in the parking lot, taking into consideration what the fee is for the various times in the lot.


int main ()                          /* beginning of main program */

{ printf ("This program calculates a parking fee for time spent parked in a parking lot.\n");
  /* write opening statement */

  /* declarations */

  int starting_hour = 4;
  int starting_minute = 20;
  int start_ampm = 'p';
  int end_hour = 7;
  int end_minute = 30;
  int end_ampm = 'p';
  int hour1, hour2, starttime, endtime;
  float totaltime;
  float price;
  float morning = 0;
  float afternoon = 0;
  float night = 0;

  /* convert start hours to minutes-position in day */
  if (start_ampm == 'a')
    hour1  = (starting_hour * 60);

  else if (start_ampm == 'p')
    hour1 = ((starting_hour + 12) * 60);

  /* convert end hours to minute-position in day */
  if (end_ampm == 'a')
    hour2 = (end_hour * 60);
  else if (end_ampm == 'p')
    hour2 = ((end_hour+12) * 60);       

  starttime = (hour1 + starting_minute);

  endtime = (hour2 + end_minute);

  totaltime = (endtime - starttime);

  /* pricing based on pay rate per period of day */
  if (starttime >= 0 && starttime < 420 && endtime >= 0 && endtime < 420)
    price = ((totaltime/60) * 1.25);

  else if (starttime >= 0 && starttime < 420  && endtime >= 420 && endtime < 1020)
    {
      morning = (((420 - starttime)/60.0)*1.25);
      afternoon = ((endtime - 420)/60.0) *.75;
      price = (morning + afternoon);
    }

  else if (starttime >= 0 && starttime < 420  && endtime >= 1020 && endtime < 1440)
    {
      morning = (((420 - starttime)/60.0)*1.25);
      afternoon = 7.5;
      night = (((endtime - 1020)/60.0)*2);
      price = (morning + afternoon + night);
    }

  else if (starttime >= 420 && starttime < 1020 && endtime >= 420 && endtime < 1020)
    {
    price = ((totaltime/60) * .75);
    }

  else if (starttime >= 420 && starttime < 1020 && endtime >= 1020 && endtime < 1440)
    {
      afternoon = (((1020 - starttime)/60.0)*.75);
      night = ((endtime - 1020)/60.0) * 2;
      price = (afternoon + night); 
    }
    
  else if (starttime >= 420 && starttime < 1020 && endtime >= 0 && endtime < 420)
    {
      afternoon = ((1020 - starttime)/60.0)*.75;
      night = 14;
      morning = (endtime/60) *1.25;
      price =(afternoon + morning + night);
    }

  else if (starttime >= 1020 && starttime < 1440 && endtime >= 1020 && endtime < 1440)
    {
      price = ((totaltime/60) * 2);
    }

  else if (starttime >= 1020 && starttime < 1440 && endtime >= 420 && endtime < 1020)
    {
      night = ((1440 - starttime)/60) * 2;
      morning = 8.75;
      afternoon = ((endtime - 420)/60) * .75;
      price = (night + morning + afternoon);
    }

  else if (starttime >= 1020 && starttime < 1440 && endtime >= 0 && endtime < 420)
    {
      night = ((1440 - starttime)/60) * 2;
      morning = ((endtime/60) *1.25);
      price = (night + morning);
    }

  /* output for user to see their numbers in action */
  printf ("Start Hour: %d %cm \n",starting_hour, start_ampm);
  printf ("End Hour: %d %cm \n",end_hour, end_ampm);
  printf ("Total Time: %.2lf hours \n",(totaltime/60));
  printf ("Money charged for morning price: %.2lf$\n", morning);
  printf ("Money charged for afternoon price: %.2lf$\n", afternoon);
  printf ("Money charged for night price: %.2lf$\n", night);
  printf ("Total price: %.2lf$ \n",price);
 
  return 0;

}
