#include <xinu.h>
#include <stdio.h>
#include <string.h>

int32 dayNumber(int32 day, int32 month, int32 year)
{

	static int32 t[] = { 0, 3, 2, 5, 0, 3,5, 1, 4, 6, 2, 4 };
	year -= month < 3;
	return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

char getMonthName[12][10] = {"January", "February", "March", "April", "May","June","July",
                            "August","September","October","November","December"
};



int32 numberOfDays[12] = {31,-1,31,30,31,30,31,31,30,31,30,31};


void printCalendar(int32 year,int32 month)
{
	int32 days;
	int32 current = dayNumber(1, month+1, year);
    if(month==1){
        if (year % 400 == 0|| (year % 4 == 0 && year % 100 != 0))
		    days=29;
	    else
		    days=28;
    }
    else
	    days = numberOfDays[month];
   
    kprintf("Days:%d",days);
	kprintf("\n\t\t%s-%d\n\n",
		getMonthName[month],year);


	kprintf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");

	int32 k;
	for (k = 0; k < current; k++)
		kprintf("\t");
    int32 j;
	for (j = 1; j <= days; j++) {
		kprintf("%d\t", j);

		if (++k > 6) {
			k = 0;
			kprintf("\n");
		}
	}
    kprintf("\n");
	
}


shellcmd xsh_cal(int32 nargs, char *args[]){
    if(nargs==3 && strncmp(args[1], "events", 7) == 0){
 
        
		int32 i = 0;
		int32 j=0;
		uint32 t1=0;
		kprintf("Events active on %s\n",args[2]);
        for(i = 0; i < tcindex;i++){
            t1 = atoi(args[2]);
			if(args[2]>=tctable[i].startTime && args[2]<=tctable[i].endTime){
				printf("ID:%d\tMessage:%s\tStartTime:%d\tEndTime:%d\n",i,tctable[i].message,tctable[i].startTime,tctable[i].endTime);
			}
        }
        
    }
	else if(nargs==3){
		int32 month = atoi(args[1]);
		int32 year = atoi(args[2]);

        if(month<1 || month>12){
            kprintf("Enter valid month number\n");
        }
        else{
            printCalendar(year,month-1);
        }
	}

    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		kprintf("Show monthly calendar\n");
        kprintf("Command format: cal <monthno.(1-12)> <year(YYYY)>\n");
		return 0;
	}
	
    return 0;
}