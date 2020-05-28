#include "intal.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define atoa(x) #x

int val(char c) 
{
	return c - '0';
}

int min(int i,int j)
{
	return i<j?i:j;
}

char * padZero(const char* ar,int l)
{
	int i = 0;
	char *pad = (char *)malloc((l+strlen(ar)+1)*sizeof(char));
	for(i = 0;i < l;i++)
	{
		pad[i] = '0';	
	} 
	strcat(pad,ar);		
	return pad;
}

char * unpadZero(char *str1){
	char * str = str1;
	 
	int i = 0;
 	int n =strlen(str);
	while(str[i]=='0' && str[i] !='\0'){
		str++;
	}
	char * unpad;
	unpad = (char*)malloc(sizeof(char)*(n - i));
	strcat(unpad,str);
	return unpad;
}	

char *rev(char *r)// Reversing the whole string.
{
	
	int i;
	char tmp;
    int mid=strlen(r)/2;
    for(i=0;i<mid;i++)
    {
    	tmp=r[i];
    	r[i]=r[strlen(r)-i-1];
    	r[strlen(r)-i-1]=tmp;

    }
    return r;
}

int intal1_compare(const char* intal1, const char* intal2){
	long int in1 = strlen(intal1);
	long int in2 = strlen(intal2);
	char * s1,*s2;
	//printf("%s\n%s\n\n",intal1,intal2);
	int diff  = in1-in2;
	if(diff>0){
		s2 = padZero(intal2,diff);
	}
	else{
		s1 = padZero(intal1,(diff*(-1)));
	}
	int res;
	if(diff>0){
		res = strcmp(intal1,s2);
		free(s2);
	}
	else{
		res = strcmp(s1,intal2);
		free(s1);
	}
	if(res<0){
		return -1;
	}else if(res>0){
		return 1;
	}else{
		return 0;
	}
	
}

int intal_compare(const char* s1, const char* s2){
	
	int res;
	long int in1 = strlen(s1);
	long int in2 = strlen(s2);
	if(in1>in2){
		
		return 1;
	}
	else if(in1<in2){
		
		return -1;
	}
	else{
		res = strcmp(s1,s2);		
		
		if(res<0){
			return -1;
		}else if(res>0){
			return 1;
		}else{
			return 0;
		}
	}
	
}





char* intal_multiply(const char* intal1, const char* intal2)
{

	int n1=strlen(intal1);
	int n2=strlen(intal2);

	if(!strcmp(intal1,"0") || !strcmp(intal2,"0"))
	{
		char *s=(char*)malloc(sizeof(char));
		strcpy(s,"0");
		return (void*)s;
	}

	int *res=(int*)malloc(sizeof(int)*(n1+n2));

	int in1=0;
	int in2=0;
	int i,j,k=0,carry,num1,num2,sum;
	for(i=n1-1;i>=0;i--)
	{	
		 carry=0;
		 num1=intal1[i]-'0';
		 in2=0;
		 for(j=n2-1;j>=0;j--)
		 {
		 	num2=intal2[j]-'0';
		 	sum=num1*num2 + res[in1+in2] + carry;
		 	carry=sum/10;
		 	res[in1+in2]=sum%10;
		 	in2++;
		 }
		 if(carry>0)
		 	 res[in1 + in2] += carry;
		 in1++;
	}
	i=n1+n2-1;

	while(i>=0 && res[i]==0)
		i--;
	if(i==-1)
	{
		char *s=(char*)malloc(sizeof(char));
		strcpy(s,"0");
		return (void*)s;
	}
	char* res1=(char*)malloc(sizeof(char)*(i+1));
	while(i>=0)
	{
		res1[k++]=res[i]+'0';
		i--;

	}
	res1[k]='\0';
	

	return (void*)res1;
}



char* intal1_mod(const char* intal1, const char* intal2)
{
	char* in1 =(char*)malloc(sizeof(char)*1001);
	char* in2 =(char*)malloc(sizeof(char)*1001);
	strcpy(in1,intal1);
	strcpy(in2,intal2);

	int flag=0;
	char* res =(char*)malloc(sizeof(char)*1001);
	strcpy(res,intal1);
	char* tmp =(char*)malloc(sizeof(char)*1001);

	while(intal_compare(res,in2)!=-1){
		strcpy(tmp,in2);
		while(intal_compare(tmp,res)==-1){
			temp=intal_multiply(tmp,"2");
		}
		res = intal_diff(tmp,res);
		flag+=1;
		flag=flag%2;
	}

	if(intal_compare(res,"0")==0){
		return 0;
	}
	if(flag==1){
		return intal_diff(in2,res);
	}

	return res;
}

char *intal_mod(const char *num1,const char *num2)
{
	    
		
	
		int comp;
		comp  = intal_compare(num1,num2);
		if(comp==-1){
			return (num1);
		}
		else {
			char * diff;
			diff = (char*)malloc(sizeof(char)*(strlen(num1)+1));
			strcat(diff,num1);
			do{
				diff = intal_diff(diff,num2);
		
			}
			while(intal_compare(diff,num2)> 0);
			char * result;
			result = unpadZero(diff);
			return result ;
		}
}

char * intal2_mod(const char* in1,const char * in2){
	int flag = 0;	
	char * result,*tmp;
	result = in1;
	char * two = "2";
	while(intal_compare(result,in2)>=0){
		tmp = in2;
		while(intal_compare(tmp,result)==-1){
			tmp = intal_multiply(tmp,two);
		}
		result = intal_diff(tmp,result);
		flag = (flag+1)%2;
	}
	
	if(intal_compare(result,"0")==0){
		return "0";}
	if(flag==1){
		return intal_diff(in2,result);
	}
	return result;
}

char* intal_add(const char* intal1, const char* intal2){
    int in1 = strlen(intal1)-1;
    int in2 = strlen(intal2)-1;
    char* s;
    if(in1>in2){
        s=(char*)malloc(sizeof(char)*(in1+3));
    }
    else{
        s=(char*)malloc(sizeof(char)*(in2+3));
    }
    int i=0;
    int carry=0;
    int s1digit,s2digit,result;
    while(in1>=0 || in2>=0){
        s1digit=s2digit=0;
        if(in1>=0)
            s1digit=intal1[in1--]-'0';
        if(in2>=0)
            s2digit=intal2[in2--]-'0';
        result=s1digit+s2digit+carry;
        carry = result/10;
        s[i++]=(result%10)+'0';
    } 
    if(carry!=0){
        s[i++]=carry+'0';
    }
    s[i]='\0';
    int n = i;
    char tmp;
    int idx=0;
    while(idx<n/2){
        tmp=s[idx];
        s[idx]=s[n-idx-1];
        s[n-idx-1]=tmp;
        idx++;
    }
    s[n]='\0';
    return s;
}

char* intal_diff(const char* intal1, const char* intal2){
    int l;
    char* str1=(char*)malloc((strlen(intal1)+1)*sizeof(char));
    strcpy(str1,intal1);
    char* str2=(char*)malloc((strlen(intal2)+1)*sizeof(char));
    strcpy(str2,intal2);
    char *temp=(char*)malloc((strlen(intal1)+1)*sizeof(char));
    char *max_string;
    max_string=(intal_compare(str1, str2)==1) ? str1 : str2;
    if(strcmp(max_string,str1)){
        strcpy(temp,str1);
        str1=(char*)malloc((strlen(str2)+1)*sizeof(char));
        strcpy(str1,str2);
        str2=(char*)malloc((strlen(temp)+1)*sizeof(char));
        strcpy(str2,temp);
    }
    char *s2_new;
    int i,j;
    j=strlen(str2)-1;
    if(strlen(str1)!=strlen(str2)){
        s2_new=(char *)malloc((strlen(str1)+1)*sizeof(char));
        s2_new[strlen(str1)+1]='\0';
        for(i=strlen(str1)-1;i>=strlen(str1)-strlen(str2);i--)
        {
            s2_new[i]=str2[j];
            j--;
        }
        for(;i>=0;i--)
        {
            s2_new[i]='0';
        }
    }
    else
    {
        s2_new=(char *)malloc((strlen(str1)+1)*sizeof(char));
        for(l=0;str2[l]!='\0';l++)
            s2_new[l]=str2[l];
        s2_new[l]='\0';
    }
    int digit1,digit2;
    char *diff=(char *)malloc((strlen(str1)+1)*sizeof(char));
    diff[strlen(str1)]='\0';
    int borrow=0;
    for(i=strlen(str1)-1;i>=0;i--)
    {
        digit1=str1[i]-'0';
        digit2=s2_new[i]-'0';
        if(digit1>=digit2){
            digit1=digit1-borrow;
            if(digit1>=digit2)
            {
                diff[i]=(digit1-digit2)+'0';
                borrow=0;
            }
            else
            {
                digit1=digit1+borrow;
                digit1=digit1+10-borrow;
                diff[i]=(digit1-digit2)+'0';
                borrow=1;
            }
        }
        else{
            digit1=digit1+10-borrow;
            diff[i]=(digit1-digit2)+'0';
            borrow=1;
        }
    }
    int len=strlen(diff);
    if(diff[0]=='0' && len!=1){
        for(i=1;i<len+1;i++)
            diff[i-1]=diff[i];
    }
    char* diff_res=unpadZero(diff);
    free(diff);
    return diff_res;
}	
	

char* intal_pow(const char* intal1, unsigned int n)
{

	int h1=0;
	int h2=0;
	if(n%2==0){
		h1 = n/2;
		h2=0;
	}
	else{	
		h1 = n/2;
		h2 = 1;
	}

	char* s1 =(char*)malloc(sizeof(char)*1001);
	strcpy(s1,intal1);

	char* tmp=(char*)malloc(sizeof(char)*1001);;
	strcpy(tmp,"1");
	for(int i=0;i<h1;i++){	
	tmp = intal_multiply(s1,tmp);
	tmp = intal_multiply(s1,tmp);
	}

	if(h2){
	tmp = intal_multiply(s1,tmp);	
	}
	free(s1);
	return tmp;

}

char *intal_bincoeff(unsigned int n, unsigned int k)
{
	char **binstr = (char **)malloc((k + 1) * sizeof(char *));
	for (int i = 0; i <= k; i++)
	{
		binstr[i] = (char *)malloc(1001 * sizeof(char));
		strcpy(binstr[i], "0");
	}
	strcpy(binstr[0], "1");

	for (int i = 1; i <= n; i++)
	{
		for (int j = min(i, k); j > 0; j--)
			binstr[j] = intal_add(binstr[j], binstr[j - 1]);
	}
	return binstr[k];
}

char *coin_row_problem(char **arr, int n)
{

	char **array = (char **)malloc((n + 1) * sizeof(char *));
	for (int i = 0; i < n; i++)
	{
		array[i] = (char *)malloc(1001 * sizeof(char));
	}
	if (n == 0)
	{
		return "0";
	}
	if (n == 1)
	{
		return arr[0];
	}

	strcpy(array[0], "0");
	strcpy(array[1], arr[0]);
	int compare = intal_compare(arr[0], arr[1]);
	if (compare == 1)
	{

		array[2] = arr[0];
	}
	else
	{
		array[2] = arr[1];
	}

	char *alternate = (char *)malloc(1001 * sizeof(char));
	char *last = (char *)malloc(1001 * sizeof(char));
	for (int i = 3; i <= n; i++)
	{
		alternate = intal_add(array[i], array[i - 2]);
		strcpy(last, array[i - 1]);
		compare = intal_compare(alternate, last);
		if (compare == 1)
		{
			strcpy(array[i], alternate);
		}
		else
		{
			strcpy(array[i], last);
		}
	}
	return array[n];
}


static void merge(char **array, int l, int m, int r)
{
	int i, j, k, l1 = m - l + 1, l2 = r - m;
	char **L = (char **)malloc(l1 * sizeof(char *));
	for (int i = 0; i < l1; i++)
	{
		L[i] = (char *)malloc(1001 * sizeof(char));
	}
	char **R = (char **)malloc(l2 * sizeof(char *));
	for (int i = 0; i < l2; i++)
	{
		R[i] = (char *)malloc(1001 * sizeof(char));
	}

	for (i = 0; i < l1; i++)
		strcpy(L[i], array[l + i]);
	for (j = 0; j < l2; j++)
		strcpy(R[j], array[m + 1 + j]);
	i = 0;
	j = 0;
	k = l;

	while (i < l1 && j < l2)
	{
		if (intal_compare(L[i], R[j]) != 1)
		{
			strcpy(array[k], L[i]);
			i++;
		}
		else
		{
			strcpy(array[k], R[j]);
			j++;
		}
		k++;
	}

	while (i < l1)
	{
		strcpy(array[k], L[i]);
		i++;
		k++;
	}

	while (j < l2)
	{
		strcpy(array[k], R[j]);
		j++;
		k++;
	}
}

static void mergeSort(char **array, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		mergeSort(array, l, mid);
		mergeSort(array, mid + 1, r);
		merge(array, l, mid, r);
	}
}
void intal_sort(char **array, int n)
{
	mergeSort(array, 0, n);
}


int intal_max(char **arr, int n){
	char* tmp;
	tmp = arr[0];
	int result=0;
	for(int i=0;i<n;i++){
		if((intal_compare(arr[i],tmp))== 1){
			tmp = arr[i];				
			result = i;
		}
	} return result;
} 


int intal_min(char **arr, int n){
	char* tmp;
	tmp = arr[0];
	int result=0;
	for(int i=0;i<n;i++){
		if((intal_compare(arr[i],tmp))== -1){
			tmp = arr[i];				
			result = i;
		}
	} return result;
} 


int intal_search(char **arr, int n, const char* key){
	int result;	
	char * key1 = key;
	for(int i=0;i<n;i++){
		key1=key;
		if(intal_compare(arr[i],key1)==0){
			result= i;
			break;
		}
	}
	return result;
	}

char* intal_fibonacci(unsigned int n){
	char * tmp1 = (char*)malloc(sizeof(char)*1001);
	char * tmp2 = (char*)malloc(sizeof(char)*1001);
	char* tmp3 = (char*)malloc(sizeof(char)*1001);
	tmp2 = strcat(tmp2,"0");
	tmp3 = strcat(tmp3,"1");
	if(n==0){
		return tmp2;
	}else if (n==1){
		return tmp3;
	}else{
		for(int i = 0;i<n;i++){
		 tmp1 = intal_add(tmp2,tmp3);
		 strcpy(tmp3,tmp2);
		 strcpy(tmp2,tmp1);
		}
		return tmp1;
	}
}

char* intal_factorial(unsigned int n){
	char * tmp1 = (char*)malloc(sizeof(char)*1001);
	char * tmp2 = (char*)malloc(sizeof(char)*1001);
	char* tmp3 = (char*)malloc(sizeof(char)*1001);
	tmp2 = strcpy(tmp2,"1");
	tmp3 = strcpy(tmp3,"2");
	if(n==0){
		return tmp2;
	}
	else if(n==1){
		return tmp2;}
	else{
		for(int i=1;i<n;i++){
			tmp1 = intal_multiply(tmp2,tmp3);
			strcpy(tmp2,tmp1);
			tmp3 = intal_add(tmp3,"1");
			}
		
		return tmp1;
	}
}
	
char* intal_gcd(const char* intal1, const char* intal2)
{
	char* result = (char*)malloc(sizeof(char)*1001);
	if(intal1_compare(intal1,"0")==0)
	{
		strcpy(result,intal2);
		return result;
	}
	strcpy(result,intal_gcd(intal1_mod(intal2,intal1),intal1));
	return result;
}





















	


	

