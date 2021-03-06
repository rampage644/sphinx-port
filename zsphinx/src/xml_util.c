/*
 * xml_util.c
 *
 *  Created on: Apr 2, 2014
 *      Author: Volodymyr Varchuk
 */


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "xml_util.h"

char * str_to_lower_case ( char *str )
{
	int  i = 0;
	char *buff = NULL;

	buff = (char *) malloc ( sizeof (char) * ( strlen( str ) + 1 ) );
	while ( str [i] != '\0' )
		buff [i] = (char) tolower ( (int) str[i++] );
	buff[i] = '\0';

	return buff;
}

int open_xml_ ( char *XML_file )
{
	char *XML_open =
"<?xml version=\"1.0\" encoding=\"utf-8\"?> \n\
<sphinx:docset>\n\
<sphinx:schema>\n\
<sphinx:field name=\"CONTENT_FIELD\" type=\"string\" />\n\
<sphinx:field name=\"PATH_INFO_FIELD\" type=\"string\" />\n\
<sphinx:attr name=\"PATH_INFO\" type=\"string\" />\n\
<sphinx:attr name=\"TIMESTAMP\" type=\"timestamp\" />\n\
<sphinx:attr name=\"CONTENT_LENGTH\" type=\"int\" />\n\
</sphinx:schema>\n\
\n";
	int fd = 0;
	int bwrite = 0;
	char * XML_open_lower = NULL;
	XML_open_lower = str_to_lower_case( XML_open );
	fd = open ( XML_file, O_WRONLY | O_CREAT | O_TRUNC, S_IROTH | S_IWOTH | S_IRUSR | S_IWUSR );
	if (fd <= 0)
	{
		fprintf (stderr, "error open %s file", XML_file);
		return -1;
	}
	bwrite = write ( fd, XML_open_lower, strlen ( XML_open_lower ) );
	free (XML_open_lower);
	return fd;
}

int close_xml_ (int fd)
{
	char *XML_close = "</sphinx:docset>";
	int bwrite = 0;
	bwrite = write ( fd, XML_close, strlen ( XML_close ) );
	close ( fd );
	return 0;
}

int open_xml_document_ ( int fd, unsigned long int docID )
{
	char *XML_ = "<sphinx:document id=\"%zu\">\n";
	char XML[strlen ( XML_ ) + 25];
	int bwrite = 0;
	sprintf ( XML, XML_, docID );
	bwrite = write ( fd, XML, strlen ( XML ) );
	return 0;
}

int close_xml_document_ (int fd)
{
	char *XML = "</sphinx:document>\n\n";
	int bwrite = 0;
	str_to_lower_case( XML );
	bwrite = write ( fd, XML, strlen ( XML ) );
	return 0;
}

int write_XML_Elemet_ (int fd, char *elemeNtname, char *element)
{
	int bwrite = 0;
	int strSize = 50; //stock
	char * elementName_lower = NULL;
	elementName_lower = str_to_lower_case( elemeNtname );
	if (element != NULL)
		strSize += strlen(element) * 2;
	if (elementName_lower != NULL)
		strSize += strlen(elementName_lower);
	else
	{
		printf ("Error. Wrong element name\n");
		return 0;
	}
	char *str = (char*) malloc (sizeof (char) * strSize);
	sprintf (str, "<%s><![CDATA[%s]]></%s>\n", elementName_lower, element, elementName_lower);
	bwrite = write (fd, str, strlen (str));
	free(elementName_lower);
	return bwrite;
}

int write_XML_Elemet_Size (int fd, char *elemeNtname, char *element, size_t e_size)
{
	int bwrite = 0;
	int strSize = 50; //stock
	char *temp = NULL;
	char *elementName_lower = NULL;
	elementName_lower = str_to_lower_case( elemeNtname );
	int temp_len = 0, temp_total_len = 0;

	if (element != NULL)
		strSize += strlen(element) * 2;
	if (elementName_lower != NULL)
		strSize += strlen(elementName_lower);
	else
	{
		printf ("*** ZVM Error. Wrong element name\n");
		return 0;
	}

	temp = (char *) malloc ( sizeof (char) * ( 50 + e_size + strlen(elementName_lower) * 2 ) );
	sprintf ( temp, "<%s><![CDATA[", elementName_lower );
	temp_len = strlen ( temp );
	memcpy( temp + temp_len, element, e_size );
	sprintf ( temp + temp_len + e_size, "]]></%s>\n", elementName_lower );
	temp_total_len = temp_len + e_size + strlen ( temp + + temp_len + e_size );

	//char *str = (char*) malloc (sizeof (char) * strSize);
	//sprintf (str, "<%s><![CDATA[%s]]></%s>\n", elemeNtname, element, elemeNtname);

	bwrite = write (fd, temp, temp_total_len);
	free( temp );
	free(elementName_lower);

	return bwrite;
}

int XML_filter ( char *buff, size_t size_buff )
{
	size_t i;

	for ( i = 0; i < size_buff; i++)
		if ( (buff [i] == '<') || (buff [i] == '>') || (buff [i] == '\"') || (buff [i] == '&') )
			buff [i] = ' ';
	return 0;
}

int do_XML ( char * XML_name )
{

	return 0;
}

void write_doc_toxml (int xml_fd, unsigned long int docID_CRC32, char * text, size_t size_text, char *fileName, char *fileLenBuff )
{
	open_xml_document_( xml_fd, docID_CRC32 );
	write_XML_Elemet_Size( xml_fd, "CONTENT_FIELD", text, size_text );
	write_XML_Elemet_( xml_fd, "PATH_INFO_FIELD", fileName );
	write_XML_Elemet_( xml_fd, "PATH_INFO", fileName );
	write_XML_Elemet_( xml_fd, "TIMESTAMP", "");
	write_XML_Elemet_( xml_fd, "CONTENT_LENGTH", fileLenBuff );
	close_xml_document_( xml_fd );
	return;
}

char * get_message_ID_from_html ( char *file_name )
{
	char *id_pattern = "<!-- id=";
	char buff [0x1000];
	char *message_id = NULL;
	FILE *f;
	f = fopen ( file_name, "r" );
	while ( fgets (buff,sizeof(buff), f) != NULL)
	{
		//<!-- id="CAK2fmCx=8Cv6+s5O8Lt2FiQzbsxgoQd892ONLEuCrsRwTWDoMQ_at_mail.gmail.com" -->
		if (strlen ( buff ) > 0)
			if ( strstr ( buff, id_pattern ) != NULL )
			{
				message_id = (char *) malloc ( sizeof ( char ) * strlen (buff) );
				memcpy ( message_id, buff + 9, strlen (buff) - 6 - 9 );
				message_id [ strlen (buff) - 6 - 9 ] = '\0';
				break;
			}
	}
	fclose (f);
	return message_id;
}
