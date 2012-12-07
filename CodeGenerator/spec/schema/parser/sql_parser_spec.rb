require 'spec_helper'

require 'schema/parser/sql_parser'

describe 'SqlParser' do
  it 'should parse a CREATE TABLE statement' do
    sql = <<eos
create table 'my_table' (
  int integer not null,
  dt timestamp not null,
  varch varchar(255) not null,
  ch char(255) not null,
  num numeric(12,2) not null,
  primary key (int, dt)
);
create index 'my_index' on 'my_table' ('dt', 'ch');
eos
    parser = Schema::SqlParser.new
    schema = parser.parse(sql)
    schema.wont_be_nil
    schema.tables.wont_be_empty
  end
end
