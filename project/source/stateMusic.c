#include <msp430.h>
#include "timeMethods.h"
#include "stateMachines.h"
#include "buzzer.h"

static char enable = 0;
static char loc = -1;
//             A     D     F     A     D     F     A     C     B     G     F     G     A     D     G     E     D
int notes[] = {4545, 6811, 5727, 4545, 6811, 5727, 4545, 3822, 4049, 5102, 5727, 5102, 4545, 6811, 7644, 6067, 6811};
int length[] = {250, 500, 250, 250, 500, 250, 125, 125, 250, 250, 125, 125, 250, 250, 125, 125, 1000};
int songOfTime[18][2] = {{4545,250}, {6811,500}, {5727, 250}, {4545,250}, {6811,500}, {5727,250}, {4545,125}, {3822,125}, {4049,250}, {5102,250}, {5727,125}, {5102,125}, {4545,250}, {6811,250}, {7644,125}, {6067,125}, {6811,750},{0,0}};
void setEnable(int signal)
{
  if (signal == -1)
    {
      enable = (enable)?0:1;
    }
  else{
    enable = signal;
  }
  if (!enable)
    {
      playNote(0);
    }
  else
    {
      setCycle(1);
    }
}
void setLocation(int idx)
{
  if (idx < 0)
    {
      loc = loc + idx;
      loc = (loc < 0)?0:loc;
    }
  else
    {
      loc = -1;
    }
  setCycle(1);
}
void advanceMusic()
{
  if (enable)
    {
      loc++;
      if (loc > 18)
	{
	  loc = 0;
	}
      //playNote(1000);
      //playNote(notes[loc]);
      //setCycle(length[loc]);
      playNote(songOfTime[loc][0]);
      setCycle(songOfTime[loc][1]);
    }
}
