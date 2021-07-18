#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct entry
{
char person_name[50];
char address[50];
char city[50];
char email[50];
char contact_no[50];
char pincode[50];
struct entry *left_ptr;
struct entry *right_ptr;
}*temporary,*new_entry,*left,*right;

typedef struct entry *list;

void newentry()
{
char na[50],phno[50],pin[50],email[50],address[50],city[50];
int i,k=0;
printf("\n\nCredentials for New entry :\n");
printf("Name:\n");
scanf("%s",na);
printf("E-mail ID :\n");
scanf("%s",email);
printf("Phone Number : \n");
scanf("%s",phno);
printf("Address:\n");
scanf("%s",address);
printf("City:\n");
scanf("%s",city);
printf("Pin:\n");
scanf("%s",pin);
new_entry=(struct entry*)malloc(sizeof(struct entry));

for(i=0;i<50;i++)
{
new_entry->person_name[i]=na[i];
new_entry->contact_no[i]=phno[i];
new_entry->pincode[i]=pin[i];
new_entry->address[i]=address[i];
new_entry->city[i]=city[i];
new_entry->email[i]=email[i];

}
if(isempty())
{
new_entry->left_ptr=new_entry->right_ptr=NULL;
left=right=new_entry;
printf("\nEntry Recorded!\n");
}
else
 {
	 temporary=left;
	 while(temporary!=NULL)
  {
	  i=strcmp(new_entry->person_name,temporary->person_name);
	 if(i>0)
	  temporary=temporary->right_ptr;
	  else if(i==0){
		printf("person_name Already Exists.Entry cannot be Added");
	  k=1;
	  break;
	 }
     else if(i<0)
	    break;
  }
	 if(k!=1)
	 {
		if(temporary==left)
	{
	  new_entry->left_ptr=NULL;
	  new_entry->right_ptr=left;
	  left->left_ptr=new_entry;
	  left=new_entry;
	  printf("Entry Recorded");
	 }
	 else if(temporary==NULL)
	{
	  new_entry->right_ptr=NULL;
	  new_entry->left_ptr=right;
	  right->right_ptr=new_entry;
	  right=new_entry;
	  printf("Entry Recorded!");
	 }
	 else
	{
	new_entry->right_ptr=temporary;
	new_entry->left_ptr=temporary->left_ptr;
	temporary->left_ptr=new_entry;
	new_entry->left_ptr->right_ptr=new_entry;
	printf("Entry Recorded!");
	}
  }
  }
}

void alldisp()
{
int n=1;
if(!isempty())
{
temporary=left;
while(temporary!=NULL)
{
printf("[%d]Name:%s\nE-mail ID:%s\nAddress:%s\nCity:%s\nContact.No:%s\nPin:%s\n",n,temporary->person_name,temporary->email,temporary->address,temporary->city,temporary->contact_no,temporary->pincode);
temporary=temporary->right_ptr;
n++;
}
}
else
printf("\nContact Book doesn't contain entries!\n");
}

void entry_delete(char todelete[50])
{
int i;
if(isempty())
printf("\nContact Book doesn't contain entries!\n ");
else{
temporary=left;
while(temporary!=NULL)
{
i=strcmp(temporary->person_name,todelete);
if(i==NULL)
{
if(left==right)
{
left=right=NULL;
printf("\nDeleted!\n");
break;
}
else if(temporary==left)
  {
  left=left->right_ptr;
  left->left_ptr=NULL;
  printf("\nDeleted!\n");
  break;
  }
else if(temporary==right)
{
right=right->left_ptr;
right->right_ptr=NULL;
printf("\nDeleted!\n");
break;
}
else{
temporary->left_ptr->right_ptr=temporary->right_ptr;
temporary->right_ptr->left_ptr=temporary->left_ptr;
printf("\nDeleted!\n");
break;
}
}
temporary=temporary->right_ptr;

}
if(temporary==NULL)
printf("Entry isn't part of address book!");
}
}

int isempty()
{
return left==NULL;
}

void makempty()
{
left=right=NULL;
printf("Address Book is Emptied");
}


void display_entry(char sample[50])
{
int i,p=1;
if(isempty())
printf("\nContact Book doesn't contain entries!\n");
else
{
temporary=left;
while(temporary!=NULL)
{
i=strcmp(temporary->person_name,sample);
if(i==NULL)
{if(p==1)
printf("Entry found!");
 else if(p==2)
 printf("Entry found!");
 else if (p==3)
 printf("Entry Found!");
 else
printf("Entry Found!");
printf("\n\nName:%s\nE-mail ID:%s\nAddress:%s\nCity:%s\nContact.No:%s\nPin:%s\n\n",temporary->person_name,temporary->email,temporary->address,temporary->city,temporary->contact_no,temporary->pincode);
break;
}
temporary=temporary->right_ptr;
p++;
}
if(temporary==NULL)
printf("Entry isn't part of address book!");
}
}


int main()
{
int left=1,m;
char n[50];

while(left!=8)
{

printf("\n\n         CONTACT BOOK APPLICATION USING DOUBLY LINKED LIST        ");
printf("\n\nCHOICES AVAILABLE : \n\n");
printf("1-New Entry\n");
printf("2-Display Contact Details\n");
printf("3-Delete a contact\n");
printf("4-Display All Contacts\n");
printf("5-Delete All Contacts\n");
printf("6-Save A Contact\n");
printf("7-Load Contacts\n");
printf("8-Delete All Saved Files\n");
printf("9-End\n\n");
printf("Please Enter your choice : ");
scanf("%d",&left);
printf("\n\n");
switch(left)
{
case 1:
newentry();
break;
case 2:
printf("Please Enter Name : ");
scanf("%s",&n);
display_entry(n);
break;
case 3:
printf("Please Enter Name :");
scanf("%s",&n);
entry_delete(n);
break;
case 4:
alldisp();
break;
case 5:
makempty();
break;
case 6:
s_entry();
break;
case 7:
lo_entry();
break;
case 8:
alldel();
break;
case 9:
printf("Thank You!");
break;
default:
printf("Invalid Choice");
break;
}
}
getch();
}
void s_entry()
{
char n[50];
int c;
printf("\n\nPlease Enter Name :");
scanf("%s",n);
list t;
if(isempty())
printf("\nContact Book doesn't contain entries!\n ");
else
{
FILE *f;
f=fopen("entry.txt","a");
int i;
t=left;
while(t!=NULL)
{
i=strcmp(t->person_name,n);
if(i==0)
{
fprintf(f,"Name : %s\nE-Mail : %s\nAddress : %s\nCity : %s\ncontact_no : %s\nPincode : %s\n",t->person_name,t->email,t->address,t->city,t->contact_no,t->pincode);
//fprintf(f,"%s %s %s %s %s %s %",t->person_name,t->email,t->address,t->city,t->contact_no,t->pincode);
printf("Saved!");
printf("Would you like to enter another contact?\n1:Yes\n2:No\n");
scanf("%d",&c);
if(c==1)
s_entry();
else if(c==2)
break;
}
t=t->right_ptr;

}
fclose(f);
if(t==NULL)
printf("\nEntry isn't part of address book!\n");
}

}
void lo_entry()
{
int i=1;
//list t;
char line[255];
FILE * f  = fopen("entry.txt","r");;
    //char line[255];
    //f=fopen("entry.txt","r");
//	if(f==NULL)
//	{
//	printf("Cannot Open");
//	exit(1);
//	}
while(!feof(f)){
//    printf(i);
//    printf("\n");
//        for(int k=0;k<6;k++){
//            //char line[255];
    fgets(line, 255, f);
    printf("%s",line);
 //   printf("\n");
//        }
    //i++;
    }
	//while(fscanf(f,"Name : %s\nE-Mail : %s\nAddress : %s\nCity : %s\ncontact_no : %s\nPincode : %s\n",t->person_name,t->email,t->address,t->city,t->contact_no,t->pincode)!=EOF)
	//while(fscanf(f,"%s %s %s %s %s %s",t->person_name,t->email,t->address,t->city,t->contact_no,t->pincode)!=EOF)
//    {
//    printf("[%d] Name : %s\nE-Mail : %s\nAddress : %s\nCity : %s\ncontact_no : %s\nPincode : %s\n",i,t->person_name,t->email,t->address,t->city,t->contact_no,t->pincode);
//	i++;
//    }
	fclose(f);
	}
	void alldel()
	{
	FILE *f;
	f=fopen("entry.txt","w");
	fclose(f);
	printf("All files have been deleted!");
	}
