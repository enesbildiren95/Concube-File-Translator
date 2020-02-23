#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>
#include <stdbool.h>
#include <json/json.h>
#define BUFFER_SIZE 125600



static void print_element_names_to_file_create_csv(xmlNode * a_node);
static void convert_xml_to_csv(xmlNode * a_node);
//static void convert_csv_to_xml(int a, FILE *fileout, FILE *fileinp);

//static void json_parse(json_object * jobj);
//static void json_read();
//static void csv_to_xml(char *filexml, char *filecsv2,int argc,char *argv[]);
//static json_object *jobjRoot;
//static json_o *j_child;
//static void csv_to_xml();
int tag = 1;
int fileopen = 1;
xmlNode *root_element = NULL;
FILE *f;
FILE *randomf;
const char* tok;
int outputE = 0;
char *s = NULL; char *t = NULL; char *typeOfFile2 = NULL; char *typeOfFile1 = NULL;

void json_read();
static char array[BUFFER_SIZE];
FILE *read, *write;
int countkey = 1;
void json_parse_xml_comp();
void json_parse_array_xml_comp();
void json_parse_xml();
void json_parse_array_xml();
void json_parse_csv();
void json_parse_array_csv();
void json_read_xml_comp(char *file5, char *file6);
void json_read_csv(char *file1, char *file2);
void json_read_xml(char *file3,char *file4);


int main(int argc, char *argv[])
{	
	
	
	
	xmlDoc *doc = NULL;
	
	char *Filenamei;
	char *Filenameo;
	char *outputFormat;
	int compressed = 0;
	int ot = 0;
	int j;
	
	
	
	int i;
	
	for(i = 1; i < argc; i++){
	if(0 == strcmp(argv[i],"-i")){
	 Filenamei = (char *)malloc(sizeof(argv[i+1]));
	 strcpy(Filenamei,argv[i+1]);
	 s = strstr(Filenamei,".");
	 typeOfFile1 = strchr(Filenamei,'.');
	}
	else if(0 == strcmp(argv[i],"-o")){
	    if(outputE == 0){
	Filenameo = (char *)malloc(sizeof(argv[i+1]));
	 strcpy(Filenameo,argv[i+1]);
	 ot = ot +1;
	 outputE = 1;
	 t = strstr(Filenameo,".");	
	 typeOfFile2 = strchr(Filenameo,'.');
      }
      else{
	    printf("ERROR");
	    outputE = 3;
	  }
	  

	}
	else if(0 == strcmp(argv[i],"-true")){
	 compressed = 1;
	}
	else if(0 == strcmp(argv[i],"-t")){
		if(outputE == 0){
		
	  outputFormat = (char *)malloc(sizeof(argv[i+1]));
	  strcpy(outputFormat, argv[i+1]);
	  outputE = 2;
	}
	else {
	  printf("ERROR");
	  outputE = 3;
	}
}
	}	
	
 /*
	if(typeOfFile1 != NULL){
	if(0 !=strcmp(typeOfFile1,".csv") && 0 !=strcmp(typeOfFile1,".xml") && 0 !=strcmp(typeOfFile1,".json")){
	printf("!!Plez enter a input file\n");
	}
	
	else if(0 !=strcmp(typeOfFile2,".csv") && 0 !=strcmp(typeOfFile2,".xml") && 0 !=strcmp(typeOfFile2,".json")){
		printf("!!Plez enter a output file\n");
	}
    }
else{
  printf("ERROR");
}*/

	
	if(outputE == 1 || outputE == 2){
	    
	    if(0 ==strcmp(s,".csv")){
			  if(outputE == 1){
			     if(0 == strcmp(t,".xml") && compressed == 0){
				    f = fopen("qweee.json","w");
				    parse_csv(Filenamei,f);
				    fclose(f);
			        //json_read_xml(f,Filenameo);
			
				 }
				 else if(0 == strcmp(t,".xml") && compressed == 1){
				    f = fopen("qweee.json","w");
				    parse_csv(Filenamei,f);
				    fclose(f);
			        //json_read_xml_comp(f,Filenameo);
			
				 }
				 else if(0 == strcmp(t,".json") && compressed == 0){
			  printf("%s","convert csv to json");
			  parse_csv(Filenamei,Filenameo);
			  // convert csv to json
			  } 
			  else{printf("Wrong Output Type"); }
			  }
			  
			  
			  
			  else if(outputE == 2){
			   if(0 == strcmp(outputFormat,"xml") && compressed == 0){
				    f = fopen("default.json","w");
				    parse_csv(Filenamei,f);
				    fclose(f);
			        //json_read_xml(f,Filenameo);
			
				 }
				 else if(0 == strcmp(outputFormat,"xml") && compressed == 1){
				    f = fopen("default.json","w");
				    parse_csv(Filenamei,f);
				    fclose(f);
			        //json_read_xml_comp(f,"random.xml");
			
				 } 
				 else if(0 == strcmp(outputFormat,"json") && compressed == 0){
			  printf("%s","convert csv to json");
			  parse_csv(Filenamei,"random.json");
			  // convert csv to json
			  } 
			   else{printf("Wrong Output Type"); }
			  
			  }
			
			  }
			  
		  if(0 ==strcmp(s,".json")){
			  if(outputE == 1){
			     if(0 == strcmp(t,".xml") && compressed == 0){
				 json_read_xml(Filenamei,Filenameo);
			
				 }
				 else if(0 == strcmp(t,".xml") && compressed == 1){
				 json_read_xml_comp(Filenamei,Filenameo);
			
				 }
				 else if(0 == strcmp(t,".csv") && compressed == 0){
			  json_read_csv(Filenamei,Filenameo);

			  }
			   else{printf("Wrong Output Type"); }
			   
			  }
			  
			  
			  
			  else if(outputE == 2){
			   if(0 == strcmp(outputFormat,"xml") && compressed == 0){
				    json_read_xml(Filenamei,"random.xml");
			
				 }
				 else if(0 == strcmp(outputFormat,"xml") && compressed == 1){
				    json_read_xml_comp(Filenamei,"random.xml");
			
				 } 
				 else if(0 == strcmp(outputFormat,"csv") && compressed == 0){
			        json_read_csv(Filenamei,"random.csv");
			  } 
			   else{printf("Wrong Output Type"); }
			  
			  }
			
			  }
		
			  if(0 ==strcmp(s,".xml")){
			  if(outputE == 1){
			     if(0 == strcmp(t,".json") && compressed == 0){
				doc = xmlReadFile(Filenamei, NULL, 0);
	   root_element = xmlDocGetRootElement(doc);
	 
	  
	     f = fopen("default.csv", "w");
	   
	  print_element_names_to_file_create_csv(root_element);
	   
	  fclose(f);
	  parse_csv("default.csv",Filenameo);
			
				 }
				 
				 else if(0 == strcmp(t,".csv") && compressed == 0){
	   doc = xmlReadFile(Filenamei, NULL, 0);
	   root_element = xmlDocGetRootElement(doc);
	
	  
	     f = fopen(Filenameo, "w");
	   
	  print_element_names_to_file_create_csv(root_element);
	   
	  fclose(f);
	   

			  }
			   else{printf("Wrong Output Type"); }
			   
			  }
			  
			  
			  
			  else if(outputE == 2){
			   if(0 == strcmp(outputFormat,"json") && compressed == 0){
				   doc = xmlReadFile(Filenamei, NULL, 0);
	   root_element = xmlDocGetRootElement(doc);
	 
	  
	     f = fopen("default.csv", "w");
	   
	  print_element_names_to_file_create_csv(root_element);
	   
	  fclose(f);
	  parse_csv("default.csv","random.json");
			
				 }
				 
				 else if(0 == strcmp(outputFormat,"csv") && compressed == 0){
	   doc = xmlReadFile(Filenamei, NULL, 0);
	   root_element = xmlDocGetRootElement(doc);
	
	  
	     f = fopen("random.csv", "w");
	   
	  print_element_names_to_file_create_csv(root_element);
	   
	  fclose(f);
	   
			  } 
			   else{printf("Wrong Output Type"); }
			  
			  }
			
			  }
		 else{printf("Wrong Input Type"); }
			  
		
		}
			  
			  
			  

	
	

	
	

	xmlFreeDoc(doc);
	
	
	xmlCleanupParser();
	
		 
	return(0);


}



static void print_element_names_to_file_create_csv(xmlNode *a_node){
	


    xmlNode *cur_node = NULL;
    xmlNode *prev_node = a_node;
	
	for(cur_node = a_node; cur_node != NULL; cur_node = cur_node->next)
	{

		if(cur_node->type == XML_ELEMENT_NODE)
		  {
			
			if(cur_node->children->next != NULL)
			  {
				
					print_element_names_to_file_create_csv(cur_node->children);
				
			  }
			else
			  {
				if(tag == 1)
				  {	
					fprintf(f,"%s",cur_node->name);
					if(cur_node->next->next == NULL)
					fprintf(f,"\n");
					else
					fprintf(f,", ");

				  }
				else
				{
					fprintf(f,"%s",cur_node->children->content);
					if(cur_node->next->next == NULL)
					fprintf(f,"\n");
					else
					fprintf(f,", ");
				}

				if(tag == 1 && cur_node->next->next == NULL)
		        {
			cur_node = a_node;
			tag = 0;
		        }
			  }


		}
		
	}

			
			 
}

static void convert_xml_to_csv(xmlNode *a_node){
      
xmlNode *cur_node = NULL;
	
	for(cur_node = a_node; cur_node != NULL; cur_node = cur_node->next)
	{

		if(cur_node->type == XML_ELEMENT_NODE)
		{
			
			if(cur_node->children->next != NULL)
			{
				
					convert_xml_to_csv(cur_node->children);
				
			}
			else
			{
				if(tag == 1)
				{	
					printf("%s",cur_node->name);
					if(cur_node->next->next == NULL)
					{printf("\n");}
					else
					{printf(", ");}

				}
				else
				{
					printf("%s",cur_node->children->content);
					if(cur_node->next->next == NULL)
					{printf("\n");}
					else
					{printf(", ");}
				}

				if(tag == 1 && cur_node->next->next == NULL)
		{
			cur_node = a_node;
			tag = 0;
		}
			}


		}

			
		

	}		

	
		
		
}

	

	
	
	
	void json_read_csv(char *file1, char *file2){
			
			
			read=fopen(file1,"r");
			write=fopen(file2,"w");
			
			while(fgets(array,BUFFER_SIZE,read)){}
			
			json_object *jobj = json_tokener_parse(array);
			
			json_parse_csv(jobj);
	
		}
		void json_read_xml(char *file3,char *file4){
			
			
			read=fopen(file3,"r");
			write=fopen(file4,"w");
			while(fgets(array,BUFFER_SIZE,read)){}
			
			json_object *jobj = json_tokener_parse(array);
			json_parse_xml(jobj);
			
	
		}
		void json_read_xml_comp(char *file5, char *file6){

			
			read=fopen(file5,"r");
			write=fopen(file6,"w");
			while(fgets(array,BUFFER_SIZE,read)){}
			
			json_object *jobj = json_tokener_parse(array);
			json_parse_xml_comp(jobj);
	
		}
void json_parse_array_xml( json_object *jobj, char *key) {
			  void json_parse_xml(json_object * jobj); 
			  enum json_type type;

			  json_object *jarray = jobj; 
			  if(key) {
			    jarray = json_object_object_get(jobj, key); 
			  }

			  int arraylen = json_object_array_length(jarray); 
			 
			  int i;
			  json_object * jvalue;

			  for (i=0; i< arraylen; i++){
			  if(i<0){
				jvalue = json_object_array_get_idx(jarray, 0);				
				}else{
			    jvalue = json_object_array_get_idx(jarray, i); }
			    type = json_object_get_type(jvalue);
			    if (type == json_type_array) {
			      json_parse_array_xml(jvalue, NULL);
			    }
			    
			    else {
			fprintf(write,"\n<%s>\n",key);
			      json_parse_xml(jvalue);
			fprintf(write,"</%s>",key);
				fprintf(write,"\n");
			countkey=0;
			    }
			  }
			}
			
			
void json_parse_xml(json_object * jobj) {
	enum json_type type;
	json_object_object_foreach(jobj, key, val) {
		type = json_object_get_type(val);
		
			
			
		switch (type) {
			case json_type_string:
			
		
			fprintf(write,"<%s>",key);
			
                        fprintf(write,"%s",json_object_get_string(val));
			fprintf(write,"</%s>\n",key);
			break;
			case json_type_int:
			fprintf(write,"<%s>",key);
			
                        fprintf(write,"%d",json_object_get_int(val));
			fprintf(write,"</%s>\n",key);
			break;
			case json_type_array:
			fprintf(write,"<%s>\n","person");
			json_parse_array_xml(jobj, key);
			fprintf(write,"\n</%s>","person");
			break;

		}
	}
		
}

void json_parse_xml_comp(json_object * jobj) {
	enum json_type type;
	json_object_object_foreach(jobj, key, val) {
		type = json_object_get_type(val);
		
			
			
		switch (type) {
			case json_type_string:
			
		
			fprintf(write,"%s=",key);
			
                        fprintf(write,"\"%s\",",json_object_get_string(val));
			
			break;
			case json_type_int:
			fprintf(write,"%s=",key);
			fprintf(write,"%d,",json_object_get_int(val));
			break;

			case json_type_array:
			fprintf(write,"<%s>\n","person");
			json_parse_array_xml_comp(jobj, key);
			fprintf(write,"\n</%s>","person");
			break;

		}
	}
		
}
		void json_parse_array_xml_comp( json_object *jobj, char *key) {
			  void json_parse_xml_comp(json_object * jobj); 
			  enum json_type type;

			  json_object *jarray = jobj; 
			  if(key) {
			    jarray = json_object_object_get(jobj, key); 
			  }

			  int arraylen = json_object_array_length(jarray); 
			 
			  int i;
			  json_object * jvalue;

			  for (i=0; i< arraylen; i++){
			  if(i<0){
				jvalue = json_object_array_get_idx(jarray, 0);				
				}else{
			    jvalue = json_object_array_get_idx(jarray, i); }
			    type = json_object_get_type(jvalue);
			    if (type == json_type_array) {
			      json_parse_array_xml_comp(jvalue, NULL);
			    }
			    
			    else {
			fprintf(write,"\n<%s ",key);
			      json_parse_xml_comp(jvalue);

			fseek(write,-1,SEEK_END);

			fprintf(write,"/>");
				fprintf(write,"\n");
			countkey=0;
			    }
			  }
			}


void json_parse_csv(json_object * jobj) {
	enum json_type type;
	json_object_object_foreach(jobj, key, val) {
		type = json_object_get_type(val);
		
			
			
		switch (type) {
			case json_type_string:
			if(countkey==1){
		
			fprintf(write,"%s,",key);}
			else{
                        fprintf(write,"%s,",json_object_get_string(val));
			}
			break;
			case json_type_int:
			if(countkey==1){
		
			fprintf(write,"%s,",key);}
			else{
                        fprintf(write,"%d,",json_object_get_int(val));
			}
			
			break;
			case json_type_array:
			json_parse_array_csv(jobj, key);
			
			break;

		}
     }
		
}
		void json_parse_array_csv( json_object *jobj, char *key) {
			  void json_parse_csv(json_object * jobj); 
			  enum json_type type;

			  json_object *jarray = jobj; 
			  if(key) {
			    jarray = json_object_object_get(jobj, key); 
			  }

			  int arraylen = json_object_array_length(jarray); 
			 
			  int i;
			  json_object * jvalue;

			  for (i=-1; i< arraylen; i++){
			  if(i<0){
				jvalue = json_object_array_get_idx(jarray, 0);				
				}else{
			    jvalue = json_object_array_get_idx(jarray, i); }
			    type = json_object_get_type(jvalue);
			    if (type == json_type_array) {
			      json_parse_array_csv(jvalue, NULL);
			    }
			    
			    else {
			      json_parse_csv(jvalue);
			fseek(write,-1,SEEK_END);
				fprintf(write,"\n");
			countkey=0;
			    }
			  }
			}
			
			void parse_csv(char *ffilei, char *ffileo){
			 
			 char*key[1000];
int a=0;



    FILE* stream = fopen(ffilei, "r");
    FILE* stream2 = fopen(ffileo, "w");
int countone=0;
int countword=0;
int sonuc=0;
int i;
    char line[1024];
    while (fgets(line, 1024, stream))
    {

        char* tmp = strdup(line);
	
     
   
 for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n")){
countword++;

key[a]=(char*)malloc((sizeof(char)*100));

strcpy(key[a],tok);
a++;



//printf("%s\n",tok);


}

for (tok = strtok(line, "\n");
            tok && *tok;
            tok = strtok(NULL, ",\n")){
countone++;

}




        
    } 
  
  
sonuc=countword/countone;
  
			 
			 json_object *employee = json_object_new_array();
		    
		
			// json_object *employee = json_object_new_array();
			 json_object *obje = json_object_new_object();
	int b;
	int c =0;
	for(b=0; b<countone-1; b++){
		json_object *keyname= json_object_new_object();
		for(c = 0; c < sonuc; c++){
		
		
		
		json_object *jstring1 = json_object_new_string(key[(b*sonuc)+c+sonuc]);
		json_object_object_add(keyname,key[c],jstring1);
		
		
		
	
		
		}
		json_object_array_add(employee,keyname);
		}
		
		json_object_object_add(obje,"employee",employee);
		fprintf (stream2,"%s",json_object_to_json_string(obje));
		
		
	}

			 
			 
