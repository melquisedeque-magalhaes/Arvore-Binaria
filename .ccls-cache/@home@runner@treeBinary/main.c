#include <stdio.h>
#include <stdlib.h>

#define True 1;
#define False 0;

struct Address {
  char zipCode[100];
  int number;
};

struct User {
  int id;
  char name[100];
  int age;
  char email[100];
  struct Address address;
  
  struct User *rigth;
  struct User *left;
};

void insert(struct User *user,int id);

void printTree(struct User *user);

int verifyIfExistsId(struct User *user, int id);

void createUser(struct User *user);

struct User *newNode(struct User *user);

int main(void) {

  int idCounter = 1;

  struct User user;

  struct User *pointerTree = &user;

  int menu;

  pointerTree->left = NULL;
  pointerTree->rigth = NULL;
  pointerTree->id = 0;

  do {
    printf("\n=====================================================\n\n");
    printf("Digite ( 1 ) para inserir valores na arvore binaria um valor\n");
    printf("Digite ( 2 ) para mostrar valores na arvore binaria um valor\n");
    printf("Digite ( 0 ) para sair\n");

    printf("\n=====================================================\n");

    printf("Digite sua opção: ");
    scanf("%d", &menu);

    printf("\n=====================================================\n");

    system("clear");
     
    switch(menu){
      case 0: 
        break;
        break;
      case 1: 
        printf("\n=====================================================\n");
        printf("\nInserindo Usuario ....\n");
        printf("\n=====================================================\n");

        const int isUserAlrealdyExists = verifyIfExistsId(pointerTree, idCounter);

        if(isUserAlrealdyExists)
          printf("\n Error usuario ja existe! \n");
        
        insert(pointerTree, idCounter);

        idCounter += 1;
        
        break;
      case 2:
        printf("\n=====================================================\n");
        printf("\nMostrando Usuario ....\n");
        printf("\n=====================================================\n");
        
        printTree(pointerTree);
        
        break;
      default:
        printf("\nError valor invalido, tente novamente... \n");
    }
  }while(menu > 0 && menu <= 2);
  
  return 0;
}

void printTree(struct User *user){
  if(user->id <= 0){
    printf("Arvore vazia... %d \n", user->id);
  }else {
    printf("Id: %d\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Idade: %d\n", user->age);
    printf("E-mail: %s\n", user->email);

    if(user->rigth != NULL)
      printTree(user->rigth);

    if(user->left != NULL)
      printTree(user->left);
    
  }
}

struct User *newNode(struct User *user){
  struct User *newTree = malloc(sizeof(struct User));

  newTree->rigth = NULL;
  newTree->left = NULL; 

  return newTree;
}

void createUser(struct User *user){
  getchar();
  
  printf("Digite seu nome: ");
  fgets(user->name, 100, stdin);
  fflush(stdin);

  printf("Digite sua idade: ");
  scanf("%d", &user->age);

  getchar();

  printf("Digite seu email: ");
  fgets(user->email, 100, stdin);
  fflush(stdin);

  printf("Digite seu CEP: ");
  fgets(user->address.zipCode, 100, stdin);

  printf("Digite o numero da sua casa: ");
  scanf("%d", user->address.number);
}

int verifyIfExistsId(struct User *user, int id){

  if(user->id == 0)
    return False;

  if(user->rigth == NULL)
    return False;

  if(user->left == NULL)
    return False;

  if(user->left->id != id)
    verifyIfExistsId(user->left, id);

  if(user->rigth->id != id)
    verifyIfExistsId(user->rigth, id);

  return True;
  
}

void insert(struct User *user,int id){
  
  if(user->id == 0){
    user->id = id;
    createUser(user);
  }else{
    
    if(id < user->id){
        if(user->left == NULL) {

          struct User *newTree = newNode(user);
        
          newTree->id = id;

          createUser(newTree);
    
          user->left = newTree;
        }  else {
            insert(user->left, id);
        }
    }

    if(id > user->id){
      if(user->rigth == NULL) {
        struct User *newTree = newNode(user);
        
        newTree->id = id;

        createUser(newTree);
  
        user->rigth = newTree;
      }
      else {
        insert(user->rigth, id);
      }
    }
    
  }

  printf("\n inserindo usuario ...\n");

  system("clear");
}