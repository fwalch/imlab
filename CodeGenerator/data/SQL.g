grammar SQL;

options { output=AST; }

tokens {
  CREATE_TABLE='create table';
  CREATE_INDEX='create index';
  INTEGER='integer';
  VARCHAR='varchar';
  CHAR='char';
  NUMERIC='numeric';
  TIMESTAMP='timestamp';
  NOT_NULL='not null';
  PRIMARY_KEY='primary key';
}

statements
  : statement+;

statement
  : create_table
  | create_index;

create_index
  : 'create index'^ ID 'on'! ID '('! ID (','! ID)* ');'!;

create_table
  : 'create table'^ ID '('! create_table_def (','! create_table_def)* ');'!;

create_table_def
  : column
  | pk_definition;

column
  : ID^ datatype constraint*;

pk_definition
  : 'primary key'^ '('! ID (','! ID)* ')'!;

constraint
  : 'not null';

datatype
  : 'integer'
  | 'timestamp'
  | 'char'^ '('! INT ')'!
  | 'varchar'^ '('! INT ')'!
  | 'numeric'^ '('! INT ','! INT ')'!;

ID
  : ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*;

INT
  : '0'..'9'+;

WS
  : ( ' '
    | '\r'
    | '\n'
    | '\t'
    | '"'
    | '\''
    ) { $channel=HIDDEN; };
