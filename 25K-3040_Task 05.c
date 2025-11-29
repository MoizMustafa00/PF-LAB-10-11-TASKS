#include<stdio.h>
#include<string.h>
struct players
{
	char name[20];
	int age;
	char position[20];
};

struct team
{
	char name[20];
	char sport[20];
	struct players p[11];
};

void addPlayer(struct players *p)
{
	printf("Enter Player Name: ");
	fgets(p->name, sizeof(p->name), stdin);
	p->name[strcspn(p->name, "\n")] = '\0';
	printf("Enter Player Age: ");
	scanf("%d", &p->age);
	getchar();
	printf("Enter Player Position: ");
	fgets(p->position, sizeof(p->position), stdin);
	p->position[strcspn(p->position, "\n")] = '\0';
}

void searchPlayer(struct players p)
{
	printf("\nName = %s\n", p.name);
	printf("Age = %d\n", p.age);
	printf("Position = %s\n", p.position);
}

void teamDetails(struct team t, int *countPlayer)
{
	printf("\nTeam Name = %s\n", t.name);
	printf("Team Sport = %s\n", t.sport);
	int i;
	for(i=0; i<*countPlayer; i++)
	{
		printf("Player %d Name = %s\n", i+1, t.p[i].name);
		printf("Player %d Age = %d\n", i+1, t.p[i].age);
		printf("Player %d Position = %s\n", i+1, t.p[i].position);
	}
}

int main()
{
	int i;
	int choice;
	struct team t;
	int countPlayer = 0;
	char position[20];
	printf("Enter Team Name: ");
	fgets(t.name, sizeof(t.name), stdin);
	t.name[strcspn(t.name, "\n")] = '\0';
	printf("Enter Team Sport: ");
	fgets(t.sport, sizeof(t.sport), stdin);
	t.sport[strcspn(t.sport, "\n")] = '\0';
	do
	{
		printf("\nEnter Your Choice:\n");
		printf("1. Add Players\n");
		printf("2. Search a Player\n");
		printf("3. Display Team Details\n");
		printf("4. Exit\n");
		scanf("%d", &choice);
		getchar();
		switch(choice)
		{
			case 1:
				if(countPlayer >= 11)
				{
				    printf("Team is Full!\n");
				}
				else
				{
					addPlayer(&t.p[countPlayer]);
					countPlayer++;
				}
				break;
			case 2:
				{
					int found = 0;
					printf("Enter Player Position to Search For: ");
					fgets(position, sizeof(position), stdin);
					position[strcspn(position, "\n")] = '\0';
					for(i=0; i<countPlayer; i++)
					{
						if(strcmp(t.p[i].position, position) == 0)
						{
							searchPlayer(t.p[i]);
							found = 1;
						}
					}
					if(!found)
					{
						printf("Player Not Found\n");
					}
					break;
				}
			case 3:
				teamDetails(t, &countPlayer);
				break;
			case 4:
				break;
			default:
				printf("Invalid Choice Input\n");
		}
	} while(choice != 4);
	return 0;
}
