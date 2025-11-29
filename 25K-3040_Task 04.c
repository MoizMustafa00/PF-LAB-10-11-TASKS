#include<stdio.h>
#include<string.h>
struct movies
{
	char title[20];
	char genre[20];
	char director[20];
	char releaseYear[5];
	int rating;	
};

void addMovie(struct movies *m)
{
	printf("Enter the Title: ");
    fgets(m->title, sizeof(m->title), stdin);
    m->title[strcspn(m->title, "\n")] = '\0';
    printf("Enter the Genre: ");
    fgets(m->genre, sizeof(m->genre), stdin);
    m->genre[strcspn(m->genre, "\n")] = '\0';
    printf("Enter the Director: ");
    fgets(m->director, sizeof(m->director), stdin);
    m->director[strcspn(m->director, "\n")] = '\0';
    printf("Enter the Release Year (YYYY): ");
    fgets(m->releaseYear, sizeof(m->releaseYear), stdin);
    m->releaseYear[strcspn(m->releaseYear, "\n")] = '\0';
    printf("Enter the Rating (1-10): ");
    scanf("%d", &m->rating);
    getchar();
}

void searchMovie(struct movies m[], int index)
{
	printf("Movie Title: %s\n", m[index].title);
	printf("Movie Genre: %s\n", m[index].genre);
	printf("Movie Director: %s\n", m[index].director);
	printf("Movie Release Year: %s\n", m[index].releaseYear);
	printf("Movie Rating: %d\n", m[index].rating);
}

void movieDetails(struct movies m)
{
	printf("Movie Title: %s\n", m.title);
	printf("Movie Genre: %s\n", m.genre);
	printf("Movie Director: %s\n", m.director);
	printf("Movie Release Year: %s\n", m.releaseYear);
	printf("Movie Rating: %d\n", m.rating);
}

int main()
{
	int n = 20, i;
	int choice;
	struct movies mov[n];
	char add[n][n];
	int countAdd = 0;
	char genre[n];
	do
	{
		printf("\nEnter Your Choice:\n");
		printf("1. Add a Movie\n");
		printf("2. Search a Movie\n");
		printf("3. Display all Movie Details\n");
		printf("4. Exit\n");
		scanf("%d", &choice);
		getchar();
		switch(choice)
		{
			case 1:
				addMovie(&mov[countAdd]);
				countAdd++;
				break;
			case 2:
				{
					int found = 0;
					printf("Enter the Genre to Search For: ");
					fgets(genre, sizeof(genre), stdin);
					genre[strcspn(genre, "\n")] = '\0';
					for(i=0; i<countAdd; i++)
					{
						if(strcmp(mov[i].genre, genre) == 0)
						{
							searchMovie(mov, i);
							found = 1;
						}
					}
					if(!found)
					{
						printf("Invalid Genre Input!\n");
					}
					break;
				}
			case 3:
				for(i=0; i<countAdd; i++)
				{	
					movieDetails(mov[i]);
				}
				break;
			case 4:
				break;
			default:
				printf("Invalid Choice Input\n");
		}
	} while(choice != 4);
	return 0;
}
