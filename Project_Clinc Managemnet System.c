#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"
#include <string.h>
 
#define ADD  1
#define EDIT 2
#define RESERVATION 3
#define CANCEL 4

#define VIEW_PATIENT_RECORD 1
#define VIEW_TODAY_RESERVATIONS 2

#define DIFFERENT 1
#define EQUAL 0

#define DEFUALT_PASS 1234
#define PERIODS 5

#define PERIOD_1 0
#define PERIOD_2 1
#define PERIOD_3 2
#define PERIOD_4 3
#define PERIOD_5 4

#define REVERSED 0
 u8  slots[PERIODS]={1,2,3,4,5};
	
typedef struct node
{
	u8 name[30];
	u32 age;
	u8 gender[7];
	u32 id;
	u8 reservation ;
	struct node *next;
}node;

node *head = NULL;

void AddPatient(void)
{ 
    node * temp1 = (node *)malloc(sizeof(node));
	printf("please enter the id of the patient : ");
	scanf("%d",&temp1->id);	  
	u8 i = 0 ;
	if(head != NULL)
	{	 
     node *temp=head;   
  do
   {
	  if(temp->id == temp1->id)
		{
		  printf("this id is already taken before \n");
		  printf("------------------------------------\n");
		  i++;
		  break;
		}
       else
		{
	     temp=temp->next;
		}			   
	}while(temp != NULL);
   }
	
    temp1->next=head;
    head=temp1; 
	
	if(i==0)
	{
	  printf("please enter the name of patient : ");
	  fflush(stdin);
	  fgets(temp1->name,30,stdin);
      printf("please enter the age of the patient : ");
	  fflush(stdin);
	  scanf(" %d",&temp1->age);
	  printf("please enter the gender of the patient : ");
	  fflush(stdin);
	  fgets(temp1->gender,7,stdin);
	  printf("please enter the current state of resrvation (ZERO cause he is a new patient) : ");
	  scanf("%d",&temp1->reservation);
	  printf("------------------------------------------- \n");
	}
	
}

node *Editor(u32 search)
{
  u32 found=0;
  node *ptr=head;
  while(ptr!=NULL)
  {
    if (ptr->id==search)
	{
      found++;
      break;
    }
	else
	{
      ptr=ptr->next;
    }
  }
  if (found==1)
  {
    return ptr;
  }
  else
  {
	  return NULL;
  }
}
node *Editor_Reserve_Slot(u32 search)
{
  u32 found=0;
  node *ptr=head;
  while(ptr!=NULL)
  {
    if (ptr->reservation==search)
	{
      found++;
      break;
    }
	else
	{
      ptr=ptr->next;
    }
  }
  if (found==1)
  {
    return ptr;
  }
  else
  {
	  return NULL;
  }
}

void EditPatientRecord(u32 id)
{	
 if(head != NULL)
  {
	u32 flag=0;
	node *temp=head;  
      do
	   {
	    if(temp->id == id)
		  {
		    flag++;
			break;
		  }
        else
		  {
			temp=temp->next;
		  }			   
		}while(temp != NULL);
		    if(flag==1)
		      {
			    printf("please enter the new age of the patient : ");
	            scanf("%d",&temp->age);
	            fflush(stdin);
	            printf("please enter the new name of patient : ");
	            fgets(temp->name,30,stdin);
	            fflush(stdin);
	            printf("please enter the new gender of the patient : ");
	            fgets(temp->gender,7,stdin);
	            printf("------------------------------------------- \n");
				node *temp = head;
		      }
		    else
		      {
		     	printf("Incorrect ID \n"); 
			  } 
	
	}
	
}

void ViewPatientRecord(u32 id)
{
  if(head != NULL)
   {
	 node *temp=head;
    
		do{
		if(temp->id == id)
	     {
		    printf("------------------------------------------- \n");
			printf("Name:%s",temp->name);
			printf("Age:%d\n",temp->age);
			printf("id:%d\n",temp->id);
			printf("gender:%s",temp->gender);
			printf("Reservation period : %d \n",temp->reservation);
		    printf("------------------------------------------- \n");
            break;
		 }
        else
		 {
		   temp=temp->next;
		 }			   
	   }while(temp != NULL);  		 
   }
}
void DisplayAvailableSlots(void)
{
	u32 i = 0;
	for(i=0 ; i<PERIODS ; i++)
	{
		if(slots[i] != REVERSED)
	    {
		   switch(i)
		   {
			  case PERIOD_1 : 
			  {
				  printf("1- first period from 2 pm to 2:30 pm \n");
				  break;
			  }
			  case PERIOD_2 : 
			  {
				  printf("2- second period from 2:30 pm to 3 pm \n");
				  break;
			  }
			  case PERIOD_3 :
			  {
				  printf("3- third period from 3 pm to 3:30 pm \n");
				  break;
			  }
			  case PERIOD_4 :
              {
				  printf("4- fourth period from 4 pm to 4:30 pm \n");
				  
				  break;
			  }
              case PERIOD_5 :
              {
				  printf("5- fifth period from 4:30 pm to 5 pm \n");
				  break;
			  }			  
			
		   }
	   }
	}
	
}
void ReserveSlot(void)
{
	u32 id ;
	u32 slot;
	printf("please enter your id : ");
	scanf("%d",&id);
	if(head != NULL)
     {
	  u32 flag=0;
	  node *temp=head;  
      do
	   {
	    if(temp->id == id)
		  {
		    flag++;
			break;
		  }
        else
		  {
			temp=temp->next;
		  }			   
		}while(temp != NULL);
		
	if(flag ==1)
	{
	DisplayAvailableSlots();
	printf("enter the number of slot period : ");
	scanf("%d",&slot);
	if(slot>=1 && slot <=5)
	{
		node *temp1 = Editor(id);
	    u8 i ;
	
	    if(temp1->reservation == REVERSED)
	     {
		  slots[slot-1]=0;
		  temp1->reservation=slot;
		  printf("The slot is reserved successfully! \n");
		  printf("------------------------------------- \n");
	     }
         else if(temp1->reservation != REVERSED)
		 {
			 printf("This Id is already reserve a slot! \n");
		 }			 
	}
	else 
	{
		printf("WORNG PERIOD! \n");
	}
	
	}
	else
	{
		printf("This Id is not found \n");
	}
	 }
	
}
void ViewTodayReservation(void)
{
 u32 i = 0;
	for(i=0 ; i<PERIODS ; i++)
	{
		if(slots[i] == 0)
	    {
		   switch(i)
		   {
			  case PERIOD_1 : 
			  {
				  printf("1- first period from 2 pm to 2:30 pm -->");
				  node *temp=Editor_Reserve_Slot(1);
				  printf("Id : %d \n",temp->id);
				  printf("------------------------------------- \n");
				  break;
			  }
			  case PERIOD_2 : 
			  {
				  printf("2- second period from 2:30 pm to 3 pm -->");
				  node *temp=Editor_Reserve_Slot(2);
				  printf("Id : %d \n",temp->id);
				  printf("------------------------------------- \n");
				  break;
			  }
			  case PERIOD_3 :
			  {
				  printf("3- third period from 3 pm to 3:30 pm -->");
				  node *temp=Editor_Reserve_Slot(3);
				  printf("Id : %d \n",temp->id);
				  printf("------------------------------------- \n");
				  break;
			  }
			  case PERIOD_4 :
              {
				  printf("4- fourth period from 4 pm to 4:30 pm -->");
				  node *temp=Editor_Reserve_Slot(4);
				  printf("Id : %d \n",temp->id);
				  printf("------------------------------------- \n");
				  break;
			  }
              case PERIOD_5 :
              {
				  printf("5- fifth period from 4:30 pm to 5 pm -->");
				  node *temp=Editor_Reserve_Slot(5);
				  printf("Id : %d \n",temp->id);
				  printf("------------------------------------- \n");
				  break;
			  }			  
			
		   }
	   }
	}	
}
void CancelReservation(void)
{
	u32 id;
	printf("please enter the patient id : ");
	scanf("%d",&id);
	if(head != NULL)
     {
	  u32 flag=0;
	  node *temp=head;  
      do
	   {
	    if(temp->id == id)
		  {
		    flag++;
			break;
		  }
        else
		  {
			temp=temp->next;
		  }			   
		}while(temp != NULL);
	if(flag ==1)
	{
		if(temp->reservation != 0)
		{
			if(temp->reservation == PERIOD_1)
			{
				slots[temp->reservation -1]=1;
				printf("The slot cancelled succssefully! \n");
			}
			else if(temp->reservation == PERIOD_2)
			{
				slots[temp->reservation -1]=2;
				printf("The slot cancelled succssefully! \n");
			}
			else if(temp->reservation == PERIOD_3)
			{
				slots[temp->reservation -1]=3;
				printf("The slot cancelled succssefully! \n");
			}
			else if(temp->reservation == PERIOD_4)
			{
				slots[temp->reservation -1]=4;
				printf("The slot cancelled succssefully! \n");
			}
			else if(temp->reservation == PERIOD_5)
			{
				slots[temp->reservation -1]=5;
				printf("The slot cancelled succssefully! \n");
			}	
		}
	
    }

	 }
}


u32 main()
{
	u8 mode[6];
	u8 mode1[6]="admin";
	u8 mode2[6]="user";
	u32 pass,i=1;
	label2:
	while(1)
			{
		printf("please enter the mode between (admin , user) mode : ");
	    scanf("%s",&mode);
	if(strcmp(mode,mode1) == EQUAL)
	{
		 printf("please enter the pass : ");
		 scanf("%d",&pass);
		 if(pass == DEFUALT_PASS)
		 {
			 u8 choice;
			 label1:
			 printf("---------------------------------------- \n");
		     printf("To add a new patient enter 1 \n");
		     printf("To edit a record of a patient enter 2 \n");
		     printf("To reserve a slot enter 3 \n");
		     printf("To cancel a reservation enter 4 \n");
		     printf("Your choice : ");
		     scanf("%d",&choice);
			 printf("---------------------------------------- \n");
		     switch(choice)
		      {
		     	case ADD:
			    {
			      AddPatient();
			      break;
			    }
			   case EDIT :
			    {
				  u32 id;
				  printf("please enter the patient id : ");
				  scanf("%d",&id);
				  EditPatientRecord(id);
				  break;
			    }
			    case RESERVATION :
			    {
				 ReserveSlot();
				 break;
			    }
				case CANCEL :
				{
					CancelReservation();
					break;
				}
		      }
			
			 
		 }
		 else if(pass != DEFUALT_PASS)
		 {
			 for(i=1 ; i<3 ; i++)
			 {
				printf("Wrong Password!\n");
                printf("please enter the pass : ");
		        scanf("%d",&pass);
                if(pass == DEFUALT_PASS)
				{
					goto label1;
				}					
			 }
			 if(pass != DEFUALT_PASS)
			 {
				 break;
			 }
			 
		 }
	
		
		
	}
	
	else if(strcmp(mode,mode2) == EQUAL)
	{
		u8 choice;
		printf("To View Patient Record enter 1 \n");
		printf("To View Today's Reservations enter 2 \n");
		printf("Your Choice :");
		scanf("%d",&choice);
		switch(choice)
	    {
			case VIEW_PATIENT_RECORD :
			{
			   u32 id;
	           printf("please enter the patient id : ");
               scanf("%d",&id);
               ViewPatientRecord(id);
			   break;
			}
			case VIEW_TODAY_RESERVATIONS :
			{
				ViewTodayReservation();
				break;
			}
		}
	  
	}
	else
	{
		printf("WRONG MODE! \n");
		goto label2;
	}
	
}
	
	
	
	return 0 ;

	
}