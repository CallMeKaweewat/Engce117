#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//fixible code
struct studentNode
{
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList
{
protected:
    struct studentNode *start, **now;

public:
    LinkedList();
    ~LinkedList();
    void InsNode(char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    void GoFirst();
    void GoLast();
    void ShowAll();
    int FindNode(char n[]);
    struct studentNode *NowNode();
    void EditNode(char n[], int a, char s, float g);
}; // end class

void EditData(LinkedList *ll);
void AddData(LinkedList *ll);
void FindData(LinkedList *ll);
void readfile(LinkedList *ll);
void writefile(LinkedList *ll);

int main(){
    LinkedList listA;
    int menu;
    readfile(&listA);
    printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : ");
    scanf("%d", &menu);
    while (menu != 0)
    {
        switch (menu)
        {
        case 1:
            AddData(&listA);
            break;
        case 2:
            EditData(&listA);
            break;
        case 3:
            listA.DelNode();
            break;
        case 4:
            FindData(&listA);
            break;
        case 5:
            listA.ShowAll();
            break;
        } // end switch
        printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : ");
        scanf("%d", &menu);
    } // end while
    writefile(&listA);
    return 0;
} // end function
//

//adddata
void AddData(LinkedList *ll) {
  char filename[100];
  printf("Enter name of the file to add : ");
  scanf("%s", filename);

  FILE *file = fopen(filename, "a");
  if (file == NULL) {
    printf("Error opening file \n");
    return;
  }

  ll->GoFirst();
  while (ll->NowNode() != NULL) {
    studentNode *node = ll->NowNode();
    fprintf(file, "%s %d %c %f \n", node->name, node->age, node->sex, node->gpa);
    ll->GoNext();
  } 

  fclose(file);
  printf("File added successfully \n");
} // end func

//editdata
void EditFile(LinkedList *ll, char filename[]) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error opening file \n");
    return;
  }

  ll->GoFirst();
  while (ll->NowNode() != NULL) {
    studentNode *node = ll->NowNode();
    fprintf(file, "%s %d %c %f \n", node->name, node->age, node->sex, node->gpa);
    ll->GoNext();
  }

  fclose(file);
  printf("File edited successfully \n");
} // end func

//finddata
void FindData( LinkedList *ll ){
	char name[ 20 ] ;
    int age;
    char sex;
    float gpa;
    printf(  "Enter name " );
	scanf(  "%s", &name );
	if( ll->FindNode( name ) == 1 ){
		struct studentNode *shownode = ll->NowNode();
		printf( "Name: %s\n", shownode->name );
		printf( "Age: %d\n", shownode->age );
		printf( "Sex: %c\n", shownode->sex );
		printf( "GPA: %.2f\n", shownode->gpa );
		printf( "\n" );
	}else{
		printf( "Not have name is %n  \n",name );
	}
}//end func
