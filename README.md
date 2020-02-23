# Concube-File-Translator

Concube is a program which translates between csv, xml and json file
types. It reads one document of such type and creates another document written in
another file type.

Various types of experiments were made, from each compatible data types.

(XML ->CSV, CSV -> JSON, JSON -> XML, XML -> JSON, JSON -> CSV, CSV -> XML)

# Methods

<b>json_read_xml_comp(char *file5, char *file6);</b>

•JSON to XML Compressed conversion starts here. The function reads a
JSON file then calls "json_parse_xml_comp();" method for later steps
of the conversion.

<b>json_read_csv(char *file1, char *file2);</b>

•JSON to CSV conversion starts here. The function reads a JSON file
then calls "json_parse_ccsv();" method for later steps of the
conversion.

<b>json_read_xml(char *file3,char *file4);</b>

•JSON to XML conversion starts here. The function reads a JSON file
then calls "json_parse_xml();" method for later steps of the
conversion.

<b>json_parse_xml_comp();</b>

•JSON to XML Compressed conversion is continued in this method
together with "void json_parse_array_xml_comp();" method.

<b>json_parse_array_xml_comp();</b>

•JSON to XML Compressed conversion is continued in this method
together with "void json_parse_xml_comp();" method.

<b>json_parse_xml();</b>

•JSON to XML Compressed conversion is continued in this method
together with "void json_parse_array_xml();" method.

<b>json_parse_array_xml();</b>

•JSON to XML Compressed conversion is continued in this method
together with "void json_parse_xml();" method.

<b>json_parse_csv();</b>

•JSON to XML Compressed conversion is continued in this method
together with "void json_parse_array_csv();" method.

<b>json_parse_array_csv();</b>

•JSON to XML Compressed conversion is continued in this method
together with "void json_parse_csv();" method.

<b>print_element_names_to_file_create_csv(xmlNode *
a_node);</b>

•In this method an XML file is read and converted to CSV file with
sending a root tree into the method.

<b>convert_xml_to_csv(xmlNode * a_node);</b>

•In this method an XML file is read and converted to CSV and printed
on the terminal screen.

<b>parse_csv(char *ffilei, char *ffileo);</b>

•In this method CSV files being parsed and converted to JSON files.

