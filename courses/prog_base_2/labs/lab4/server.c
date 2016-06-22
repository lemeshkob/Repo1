#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> //  ptrdiff_t
#include <ctype.h>

#include "server.h"
#include "socket.h"
#include "Freelanser.h"

void server_answer(http_request_t req, socket_t * clientSocket,lanser ** freelanser)
{
    puts(req.method);
    puts(req.uri);
    if (!strcmp(req.uri, "/ScrumMaster-count"))
    {
        server_count(clientSocket,freelanser);
    }
    else
    if (!strcmp(req.uri, "/ScrumMaster/api"))
    {
        if (!strcmp(req.method, "GET"))
            server_GET_all(req,clientSocket,freelanser);
        else if(!strcmp(req.method, "DELETE"))
            server_DELETE_all(req,clientSocket,freelanser);
        else
            socket_write_string(clientSocket, "Method not allowed!\n");

    }
    else if (strncmp(req.uri, "/ScrumMaster/api/",16)==0)
    {
        if(!strcmp(req.method,"GET"))
            server_GET_id(req,clientSocket,freelanser);
        else if(!strcmp(req.method,"DELETE"))
            server_DELETE_id(req,clientSocket,freelanser);
        else if(!strcmp(req.method,"POST"))
        {
            puts("1");
            server_POST(req,clientSocket,freelanser);
        }
    }
    else if(!strncmp(req.uri,"/ScrumMaster/delete/",19))
    {
        server_DELETE_id(req,clientSocket,freelanser);
    }
    else  if(!strcmp(req.uri,"/ScrumMaster"))
    {
        server_start_page(clientSocket);
    }
    else if(!strcmp(req.uri,"/ScrumMaster/"))
    {
        server_GET_html(clientSocket,freelanser);
    }
    else if(!strcmp(req.uri,"/ScrumMaster/paste"))
    {
        server_Paste_html(req,clientSocket,freelanser);
    }
    else if(!strncmp(req.uri,"/ScrumMaster/",12))
    {
        server_GET_id_html(req,clientSocket,freelanser);
    }
    else
        socket_write_string(clientSocket,"\nHTTP1.1 404 NOT FOUND\n"
            "Content-Type: application/json\n"
            "Content-Length: %i\r\n\r\n""Freelancer not found\n");
}


void server_sent(socket_t* clientSocket, char* text)
{
    char buf[10000];
    sprintf(buf,"\nHTTP1.1 200 OK\n"
            "Content-Type: application/json\n"
            "Content-Length: %i\r\n\r\n"
            "%s\n",strlen(text),text);
    socket_write_string(clientSocket,buf);
}

char * lanser_toJSON(lanser * self)
{
    cJSON * SM = cJSON_CreateObject();
    cJSON_AddItemToObject(SM, "name", cJSON_CreateString(Freelanser_name_get(self)));
    cJSON_AddItemToObject(SM, "surname", cJSON_CreateString(Freelanser_surname_get(self)));
    cJSON_AddItemToObject(SM, "age", cJSON_CreateNumber(Freelanser_age_get(self)));
    cJSON_AddItemToObject(SM, "date", cJSON_CreateString(Freelanser_date_get(self)));
    cJSON_AddItemToObject(SM, "salary", cJSON_CreateNumber(Freelanser_salary_get(self)));
    char * jsonSM = cJSON_Print(SM);
    return jsonSM;
}

void server_count( socket_t * clientSocket,lanser** freelancer)
{
    int count=0;
    for(int i=0;i<10;i++)
        if(Freelanser_name_get(freelancer[i])!=NULL)
            count++;
    cJSON * SM = cJSON_CreateObject();
    cJSON_AddItemToObject(SM, "count", cJSON_CreateNumber(count));
    char* text =cJSON_Print(SM);
    server_sent(clientSocket,text);
}

void server_GET_all(http_request_t req, socket_t * clientSocket,lanser** freelancer)
{
    char text[10000]="";
    char * buf=NULL;
    int count=0,check=0;

    for(int i = 0; i < 10; i++)
            if(Freelanser_name_get(freelancer[i])!=NULL)
                count++;


        strcat(text, "[");
        for(int i = 0; i < 10; i++)
        {
            if(Freelanser_name_get(freelancer[i])==NULL)
            {
                i++;
            }
            else
            {
                buf = lanser_toJSON(freelancer[i]);

            strcat(text, buf);
            if(check != count-1)
            {
                strcat(text, ",");
                check++;
            }
            }
        }
        strcat(text, "]");

    server_sent(clientSocket, text);
}

void server_GET_id(http_request_t req,socket_t * clientSocket,lanser** freelancer)
{
    char text[1000]="";
    char *buf=NULL;
    int id;

    if(strpbrk(req.uri,"-0123456789"))
    {
        id=atoi(strpbrk(req.uri,"-0123456789"));
        if(id>9 || id<0)
        {
            socket_write_string(clientSocket,"HTTP1.1 404 NOT FOUND\n"
            "Content-Type: json\n"
            "Content-Length: %i\r\n\r\n"
            "Id not found");
            return;
        }
    }
    else
    {
        socket_write_string(clientSocket,"Wrong id");
        return;
    }


            buf = lanser_toJSON(freelancer[id]);

            strcat(text, buf);

    server_sent(clientSocket, text);

}

void server_DELETE_all(http_request_t req,socket_t * clientSocket,lanser** freelanser)
{
    for(int i=0; i<10; i++)
    {
        Freelanser_set(freelanser[i],NULL,NULL,0,NULL,0);
    }
    server_sent(clientSocket, "Delete success");
}

void server_DELETE_id(http_request_t req,socket_t * clientSocket,lanser** freelanser)
{
    char buf[1000]="";
    int id;

    if(strpbrk(req.uri,"-0123456789"))
    {
        id=atoi(strpbrk(req.uri,"-0123456789"));
        if(id>9 || id<0)
        {
            socket_write_string(clientSocket,"HTTP1.1 404 NOT FOUND\n"
            "Content-Type: json\n"
            "Content-Length: %i\r\n\r\n"
            "%s\n""<body>Id not found<br>"
                                  "<a href=\"/ScrumMaster/\">To Freelancers</a></body>");
            return;
        }
    }
    else
    {
        socket_write_string(clientSocket,"<body>Wrong id<br>"
                                  "<a href=\"/ScrumMaster/\">To Freelancers</a></body>");
        return;
    }

    Freelanser_set(freelanser[id],NULL,NULL,0,NULL,0);

    server_sent(clientSocket, "<body>Delete success<br>"
                                  "<a href=\"/ScrumMaster/\">To Freelancers</a></body>");
}

void server_POST(http_request_t req,socket_t * clientSocket,lanser** freelanser)
{
    const char * name= http_request_getArg(&req,"name");
    const char * surname= http_request_getArg(&req,"surname");
    const char * age= http_request_getArg(&req,"age");
    const char * date= http_request_getArg(&req,"date");
    const char * salary= http_request_getArg(&req,"salary");

    if(name==NULL || surname==NULL || age ==NULL || date==NULL || salary==NULL)
    {
        socket_write_string(clientSocket,"<body> POST argument/arguments is/are empty<br>"
                                  "<a href=""/ScrumMaster/"">To Scrum master</a></body>");
        return;
    }

    char buf[1000]="";
    int id;

    if(strpbrk(req.uri,"-0123456789"))
    {
        id=atoi(strpbrk(req.uri,"-0123456789"));
        if(id>9 || id<0)
        {
            socket_write_string(clientSocket,"<body>Id not found<br>"
                                  "<a href=""/ScrumMaster/"">To Scrum Masters</a></body>");
            return;
        }
    }
    else
    {
        socket_write_string(clientSocket,"<body>Wrong id<br>"
                                  "<a href=""/ScrumMaster/"">To Scrum Master</a></body>");
        return;
    }

    int check=0;
    int dot=0;

    for(int i=0; i<strlen(age); i++)
        if(!isdigit(age[i]))
        {
            if(age[i]=='.'||dot==0)
                dot++;
            else
                check++;
        }

    for(int i=0; i<strlen(salary); i++)
        if(!isdigit(salary[i]))
            check++;

    for(int i=0; i<4; i++)
        if(!isdigit(date[i]))
            check++;

    if(date[4]!='-')
        check++;

    for(int i=5; i<7; i++)
        if(!isdigit(date[i]))
            check++;

    if(date[7]!='-')
        check++;

    for(int i=8; i<strlen(date); i++)
        if(!isdigit(date[i]))
            check++;

    if(atoi(date+5)>12)
        check++;

    if(dot>1||dot<0)
    {
        socket_write_string(clientSocket,"<body>Invalid POST argument<br>"
                                  "<a href=""/ScrumMaster/"">To Scrum master</a></body>");
        return;
    }

    if(check==0)
    {
        Freelanser_set(freelanser[id],name,surname,atof(age),date,atoi(salary));

        server_sent(clientSocket, "<body>Post success<br>"
                                  "<a href=\"/ScrumMaster/\">To Scrum master</a></body>");
    }
    else
        socket_write_string(clientSocket,"<body>Invalid POST argument<br>"
                                  "<a href=\"/ScrumMaster/\">To Scrum master</a></body>");
}

void server_start_page(socket_t* clientSocket)
{
    char text[]="<html>"
                "<head>"
                "<title>Page Title</title>"
                "</head>"
                "<body>"
                "<h1>HELLO Word</h1>"
                "<p><a href=""/ScrumMaster/"">Scrum masterS</a></p>"
                "</body>"
                "</html>";
    socket_write_string(clientSocket,text);
}

void server_GET_html(socket_t* clientSocket,lanser ** freelancer)
{
    char buf[10000]="<html>"
                    "<head>"
                    "<title>Page Title</title>"
                    "</head>"
                    "<body>"
                    "<h1>Scrum masters</h1>";
    char text [1000]="";
    for(int i=0; i<10; i++)
    {
        if(Freelanser_name_get(freelancer[i])!=NULL)
        {
            sprintf(text,"<p><a href=""/ScrumMaster/%i"">%s %s</a></p>",i,Freelanser_name_get(freelancer[i]),Freelanser_surname_get(freelancer[i]));
            strcat(buf,text);
        }
    }
    strcat(buf,"<p><a href=""/ScrumMaster/paste"">New Scrum master</a></p>");
    strcat(buf,"</body>"
           "</html>");
    socket_write_string(clientSocket,buf);
}

void server_GET_id_html(http_request_t req,socket_t* clientSocket,lanser ** freelancer)
{
    int id;

    if(strpbrk(req.uri,"-0123456789"))
    {
        id=atoi(strpbrk(req.uri,"-0123456789"));
        if(id>9 || id<0)
        {
            socket_write_string(clientSocket,"Id not found");
            return;
        }
    }
    else
    {
        socket_write_string(clientSocket,"Wrong id");
        return;
    }
    char text [1000]="";
    char buf[10000]="<html>"
                    "<head>"
                    "<title>Page Title</title>"
                    "</head>"
                    "<body>"
                    "<h1>Scrum master</h1>";


    sprintf(text,"<p>Name:\t\t%s</p>"
            "<p>Surname:\t%s</p>"
            "<p>Age:\t\t%.2f</p>"
            "<p>Date:\t\t%s</p>"
            "<p>\tSalary:\t\t%i\n\n\n</p>"
            "<p><a href=""/ScrumMaster/"">To prev page</a></p>",
            Freelanser_name_get(freelancer[id]),
            Freelanser_surname_get(freelancer[id]),
            Freelanser_age_get(freelancer[id]),
            Freelanser_date_get(freelancer[id]),
            Freelanser_salary_get(freelancer[id])
           );
    strcat(buf,text);
    sprintf(text,"<p><a href=\"/ScrumMaster/\" onclick=\"doDelete()\">Delete Scrum master</a></p>"
                 "<script>"
                 "function doDelete(){"
                 "var xhttp=new XMLHttpRequest();"
                 "xhttp.open(\"DELETE\",\"/ScrumMaster/api/%i\",true);"
                 "xhttp.send();"
                 "}"
                 "</script>",id);
    strcat(buf,text);
    strcat(buf,"</body>"
           "</html>");
    socket_write_string(clientSocket,buf);
}

void server_Paste_html(http_request_t req,socket_t* clientSocket,lanser ** freelancer)
{
    char buf[5000]="";
    char text[5000]="";
    int id=0;
    while(Freelanser_name_get(freelancer[id])!=NULL)
    {
        id++;
        if(id>9)
        {
            strcat(buf,"<body>"
                        "Can't Post the new Scrum master<br>"
                        "<a href=""/ScrumMaster/"">Back</a>"
                        "</body>");
        }
    }
    sprintf(text, "<html>"
            "<body>"
            "<form action=""http://127.0.0.1:5000/ScrumMaster/api/%i"" method=""POST"">"
            "Name:<br>"
            "<input type=""text"" name=""name""><br>"
            "Surname:<br>"
            "<input type=""text"" name=""surname"" ><br>"
            "Age:<br>"
            "<input type=""text"" name=""age""><br>"
            "Date:<br>"
            "<input type=""text"" name=""date""><br>"
            "Salary:<br>"
            "<input type=""text"" name=""salary""><br>"
            "<input type=""submit"" value='Send POST request' />"
            "</form>"
            "</body>",id);
    strcat(buf,text);
    socket_write_string(clientSocket,buf);
}


http_request_t http_request_parse(const char * const request)
{
    http_request_t req;
    req.form = NULL;
    req.formLength = 0;
    // get method
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace
    memcpy(req.method, request, methodLen);
    req.method[methodLen] = '\0';
    // get uri
    const char * uriStartPtr = request + strlen(req.method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req.uri, uriStartPtr, uriLen);
    req.uri[uriLen] = '\0';
    // parse form data
    const char * bodyStartPtr = strstr(request, "\r\n\r\n") + strlen("\r\n\r\n");
    const char * cur = bodyStartPtr;
    const char * pairEndPtr = cur;
    const char * eqPtr = cur;
    while (strlen(cur) > 0)
    {
        pairEndPtr = strchr(cur, '&');
        if (NULL == pairEndPtr)
        {
            pairEndPtr = cur + strlen(cur);
        }
        keyvalue_t kv;
        // get key
        eqPtr = strchr(cur, '=');
        ptrdiff_t keyLen = eqPtr - cur;
        memcpy(kv.key, cur, keyLen);
        kv.key[keyLen] = '\0';
        // get value
        eqPtr++;
        ptrdiff_t valueLen = pairEndPtr - eqPtr;
        memcpy(kv.value, eqPtr, valueLen);
        kv.value[valueLen] = '\0';
        // insert key-value pair into request form list
        req.formLength += 1;
        req.form = realloc(req.form, sizeof(keyvalue_t) * req.formLength);
        req.form[req.formLength - 1] = kv;
        cur = pairEndPtr + ((strlen(pairEndPtr) > 0) ? 1 : 0);
    }
    return req;
}

const char * http_request_getArg(http_request_t * self, const char * key)
{
    for (int i = 0; i < self->formLength; i++)
    {
        if (strcmp(self->form[i].key, key) == 0)
        {
            return self->form[i].value;
        }
    }
    return NULL;
}

const char * keyvalue_toString(keyvalue_t * self)
{
    char * str = malloc(sizeof(char) * (strlen(self->key) + strlen(self->value) + 2));
    sprintf(str, "%s=%s\0", self->key, self->value);
    return str;
}

