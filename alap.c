#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;

void make_file(string File_Name, string main_prog)
{
    string file_name = File_Name;

    FILE *fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        puts("Error! Try again!");
        exit(1);
    }
    printf("# '%s' was created\n", File_Name);
    fprintf(fp, "%s", main_prog);
    fclose(fp);
}

int file_exist(string File_Name)
{
    FILE *fp = fopen(File_Name, "r");
    int is_exist = 0;
    if (fp != NULL)
    {
        is_exist = 1;
        fclose(fp);
    }
    return is_exist;
}
int main(int argc, string argv[])
{
    string program_cs = "using System;\n\npublic class Main\n{\n\tpublic static void Main()\n\t{\n\t\tSystem.Console.WriteLine(\"Hello World\");\n\t}\n}\n";
    string main_c = "#include <stdio.h>\n\nint main()\n{\n\tprintf(\"Hello World!\\n\");\n\n\treturn 0;\n}\n";
    string main_py = "#!/usr/bin/env python3\n\ndef main():\n\tprint(\"Hello World!\")\n###########################################\n\nif __name__== \"__main__\":\n\tmain()\n";
    string java= "public class HelloWorld {\n \tpublic class static void main (String [] args) {\n \t\tSystem.out.prinln(\"Hello World!\");\n \t}\n } \n";
    string flask="from flask import Flask\n app = Flask(_name_)\n\n@app.route('/')\ndef hello_world():\n\treturn 'Hello World!'\n ";
    string bash="#!/bin/bash\n echo \"Hello World\"\n";
    
    if (argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        puts("alap v1.0\n");
        puts("Usage : alap <template_id> [option]\n");
        puts("Available options: \n");
        puts("-h, --help \t\t show this help\n-v, --version \t\t version info\n--stdout \t\t don't create source file, print result to stdout\n ");
        puts("Available templates: \n");
        puts("* c \t - C source code [main.c]\n* cs \t - C# source code [program.cs]\n* py \t - Python 3 source code [main.py]\n* java \t - Java source code [Main.java]\n* flask\t - Flask source code [app.py]\n* sh \t - Bash source code [main.sh]");
    }
    else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
    {
        puts("alap v1.0");
    }
    else if (strcmp(argv[1], "c") == 0 && argc == 2)
    {
        if (file_exist("main.c") == 1)
        {
            puts("Error: the file 'main.c' already exists");
            exit(1);
        }
        else
        {
            make_file("main.c", main_c);
        }
    }
    else if (strcmp(argv[1], "py") == 0 && argc == 2)
    {
        if (file_exist("main.py") == 1)
        {
            puts("Error: the file 'main.py' already exists");
            exit(1);
        }
        else
        {
            make_file("main.py", main_py);
        }
    }
    else if (strcmp(argv[1], "cs") == 0 && argc == 2)
    {
        if (file_exist("Program.cs") == 1)
        {
            puts("Error: the file 'Program.cs' already exists");
            exit(1);
        }
        else
        {
            make_file("Program.cs", program_cs);
        }
    }
    else if (strcmp(argv[1], "java") == 0 && argc == 2)
    {
        if (file_exist("Main.java") == 1)
        {
            puts("Error: the file 'Main.java' already exists");
            exit(1);
        }
        else
        {
            make_file("Main.java", java);
        }
    }
    else if (strcmp(argv[1], "flask") == 0 && argc == 2)
    {
        if (file_exist("app.py") == 1)
        {
            puts("Error: the file 'app.py' already exists");
            exit(1);
        }
        else
        {
            make_file("app.py", flask);
        }
    }
    else if (strcmp(argv[1], "sh") == 0 && argc == 2)
    {
        if (file_exist("main.sh") == 1)
        {
            puts("Error: the file 'main.sh' already exists");
            exit(1);
        }
        else
        {
            make_file("main.sh", bash);
        }
    }
    else if (strcmp(argv[1], "cs") == 0 && strcmp(argv[2], "--stdout") == 0)
    {
        fprintf(stdout, "%s", program_cs);
        puts("");
    }
    else if (strcmp(argv[1], "c") == 0 && strcmp(argv[2], "--stdout") == 0)
    {
        fprintf(stdout, "%s", main_c);
        puts("");
    }
    else if (strcmp(argv[1], "py") == 0 && strcmp(argv[2], "--stdout") == 0)
    {
        fprintf(stdout, "%s", main_py);
        puts("");
    }
    else if (strcmp(argv[1], "java") == 0 && strcmp(argv[2], "--stdout") == 0)
    {
        fprintf(stdout, "%s", java);
        puts("");
    }
    else if (strcmp(argv[1], "flask") == 0 && strcmp(argv[2], "--stdout") == 0)
    {
        fprintf(stdout, "%s", flask);
        puts("");
    }
    else if (strcmp(argv[1], "sh") == 0 && strcmp(argv[2], "--stdout") == 0)
    {
        fprintf(stdout, "%s", bash);
        puts("");
    }
    else
    {
        puts("Error! Unknown options! Try [-h]!");
        exit(1);
    }

    return 0;
}
