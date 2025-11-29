#include<stdio.h>
#include<string.h>
struct flightInfo
{
	char flightNum[20];
	char departureCity[20];
	char destinationCity[20];
	char date[11];
	int availableSeats;
};

void bookSeat(struct flightInfo f[], int index)
{
	if(f[index].availableSeats > 0)
	{
		f[index].availableSeats--;
		printf("Seat Booked Successfully!\n");
		printf("Remaining Seats = %d\n", f[index].availableSeats);
	}
	else
	{
		printf("No Seats Available!\n");
	}
	
}

void flightDetails(struct flightInfo f)
{
	printf("\nFlight Number: %s\n", f.flightNum);
	printf("Departure City: %s\n", f.departureCity);
	printf("Destination City: %s\n", f.destinationCity);
	printf("Date: %s\n", f.date);
	printf("Available Seats: %d\n", f.availableSeats);
}

int main()
{
	int n, i;
	printf("Enter Number of Flights: ");
	scanf("%d", &n);
	struct flightInfo flights[n];
	for(i=0; i<n; i++)
	{
		printf("\nEnter Details for Flight %d:\n", i+1);
		printf("Enter Your Flight Number: ");
		scanf("%s", flights[i].flightNum);
		printf("Enter Your Departure City: ");
		scanf("%s", flights[i].departureCity);
		printf("Enter Your Destination City: ");
		scanf("%s", flights[i].destinationCity);
		printf("Enter Today's Date in (DD/MM/YYYY) Format: ");
		scanf("%s", flights[i].date);
		printf("Enter Available Seats: ");
		scanf("%d", &flights[i].availableSeats);
	}
	int choice;
	do
	{	
		printf("\nEnter Your Choice:\n");
		printf("1. Book a Seat\n");
		printf("2. Display Flight Details\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				{
				char flightNo[20];
                printf("Enter Flight Number to Book: ");
                scanf("%s", flightNo);
                int found = 0;
                for(i=0; i<n; i++)
				{
                    if(strcmp(flights[i].flightNum, flightNo) == 0)
					{
                        bookSeat(flights, i);
                        found = 1;
                        break;
                    }
                }
                if(!found)
				{
                    printf("Flight Not Found!\n");
            	}
				break;
				}
			case 2:
				for(i=0; i<n; i++)
				{
					flightDetails(flights[i]);
				}
				break;
			case 3:
				break;
			default:
				printf("Invalid Choice Input!\n");
		}
	} while(choice != 3);
	return 0;
}
