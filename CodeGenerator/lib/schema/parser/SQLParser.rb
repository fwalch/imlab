#!/usr/bin/env ruby
#
# data/SQL.g
# --
# Generated using ANTLR version: 3.2.1-SNAPSHOT Jul 31, 2010 19:34:52
# Ruby runtime library version: 1.8.11
# Input grammar file: data/SQL.g
# Generated at: 2012-11-19 21:16:54
# 

# ~~~> start load path setup
this_directory = File.expand_path( File.dirname( __FILE__ ) )
$LOAD_PATH.unshift( this_directory ) unless $LOAD_PATH.include?( this_directory )

antlr_load_failed = proc do
  load_path = $LOAD_PATH.map { |dir| '  - ' << dir }.join( $/ )
  raise LoadError, <<-END.strip!
  
Failed to load the ANTLR3 runtime library (version 1.8.11):

Ensure the library has been installed on your system and is available
on the load path. If rubygems is available on your system, this can
be done with the command:
  
  gem install antlr3

Current load path:
#{ load_path }

  END
end

defined?( ANTLR3 ) or begin
  
  # 1: try to load the ruby antlr3 runtime library from the system path
  require 'antlr3'
  
rescue LoadError
  
  # 2: try to load rubygems if it isn't already loaded
  defined?( Gem ) or begin
    require 'rubygems'
  rescue LoadError
    antlr_load_failed.call
  end
  
  # 3: try to activate the antlr3 gem
  begin
    Gem.activate( 'antlr3', '~> 1.8.11' )
  rescue Gem::LoadError
    antlr_load_failed.call
  end
  
  require 'antlr3'
  
end
# <~~~ end load path setup


module SQL
  # TokenData defines all of the token type integer values
  # as constants, which will be included in all 
  # ANTLR-generated recognizers.
  const_defined?( :TokenData ) or TokenData = ANTLR3::TokenScheme.new

  module TokenData

    # define the token constants
    define_tokens( :INTEGER => 6, :T__20 => 20, :CHAR => 8, :VARCHAR => 7, 
                   :INT => 14, :NUMERIC => 9, :ID => 13, :EOF => -1, :NOT_NULL => 11, 
                   :T__19 => 19, :WS => 15, :T__16 => 16, :CREATE_INDEX => 5, 
                   :T__18 => 18, :T__17 => 17, :CREATE_TABLE => 4, :PRIMARY_KEY => 12, 
                   :TIMESTAMP => 10 )

    # register the proper human-readable name or literal value
    # for each token type
    #
    # this is necessary because anonymous tokens, which are
    # created from literal values in the grammar, do not
    # have descriptive names
    register_names( "CREATE_TABLE", "CREATE_INDEX", "INTEGER", "VARCHAR", 
                    "CHAR", "NUMERIC", "TIMESTAMP", "NOT_NULL", "PRIMARY_KEY", 
                    "ID", "INT", "WS", "'on'", "'('", "','", "');'", "')'" )
    
  end


  class Parser < ANTLR3::Parser
    @grammar_home = SQL
    include ANTLR3::ASTBuilder

    RULE_METHODS = [ :statements, :statement, :create_index, :create_table, 
                     :create_table_def, :column, :pk_definition, :constraint, 
                     :datatype ].freeze


    include TokenData

    begin
      generated_using( "data/SQL.g", "3.2.1-SNAPSHOT Jul 31, 2010 19:34:52", "1.8.11" )
    rescue NoMethodError => error
      # ignore
    end

    def initialize( input, options = {} )
      super( input, options )


    end
    # - - - - - - - - - - - - Rules - - - - - - - - - - - - -
    StatementsReturnValue = define_return_scope 

    # 
    # parser rule statements
    # 
    # (in data/SQL.g)
    # 17:1: statements : ( statement )+ ;
    # 
    def statements
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 1 )
      return_value = StatementsReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      statement1 = nil


      begin
        root_0 = @adaptor.create_flat_list


        # at line 18:5: ( statement )+
        # at file 18:5: ( statement )+
        match_count_1 = 0
        while true
          alt_1 = 2
          look_1_0 = @input.peek( 1 )

          if ( look_1_0.between?( CREATE_TABLE, CREATE_INDEX ) )
            alt_1 = 1

          end
          case alt_1
          when 1
            # at line 18:5: statement
            @state.following.push( TOKENS_FOLLOWING_statement_IN_statements_90 )
            statement1 = statement
            @state.following.pop
            @adaptor.add_child( root_0, statement1.tree )

          else
            match_count_1 > 0 and break
            eee = EarlyExit(1)


            raise eee
          end
          match_count_1 += 1
        end

        # - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 1 )

      end
      
      return return_value
    end

    StatementReturnValue = define_return_scope 

    # 
    # parser rule statement
    # 
    # (in data/SQL.g)
    # 20:1: statement : ( create_table | create_index );
    # 
    def statement
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 2 )
      return_value = StatementReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      create_table2 = nil
      create_index3 = nil


      begin
        # at line 21:3: ( create_table | create_index )
        alt_2 = 2
        look_2_0 = @input.peek( 1 )

        if ( look_2_0 == CREATE_TABLE )
          alt_2 = 1
        elsif ( look_2_0 == CREATE_INDEX )
          alt_2 = 2
        else
          raise NoViableAlternative( "", 2, 0 )
        end
        case alt_2
        when 1
          root_0 = @adaptor.create_flat_list


          # at line 21:5: create_table
          @state.following.push( TOKENS_FOLLOWING_create_table_IN_statement_101 )
          create_table2 = create_table
          @state.following.pop
          @adaptor.add_child( root_0, create_table2.tree )

        when 2
          root_0 = @adaptor.create_flat_list


          # at line 22:5: create_index
          @state.following.push( TOKENS_FOLLOWING_create_index_IN_statement_107 )
          create_index3 = create_index
          @state.following.pop
          @adaptor.add_child( root_0, create_index3.tree )

        end# - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 2 )

      end
      
      return return_value
    end

    CreateIndexReturnValue = define_return_scope 

    # 
    # parser rule create_index
    # 
    # (in data/SQL.g)
    # 24:1: create_index : 'create index' ID 'on' ID '(' ID ( ',' ID )* ');' ;
    # 
    def create_index
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 3 )
      return_value = CreateIndexReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      string_literal4 = nil
      __ID5__ = nil
      string_literal6 = nil
      __ID7__ = nil
      char_literal8 = nil
      __ID9__ = nil
      char_literal10 = nil
      __ID11__ = nil
      string_literal12 = nil

      tree_for_string_literal4 = nil
      tree_for_ID5 = nil
      tree_for_string_literal6 = nil
      tree_for_ID7 = nil
      tree_for_char_literal8 = nil
      tree_for_ID9 = nil
      tree_for_char_literal10 = nil
      tree_for_ID11 = nil
      tree_for_string_literal12 = nil

      begin
        root_0 = @adaptor.create_flat_list


        # at line 25:5: 'create index' ID 'on' ID '(' ID ( ',' ID )* ');'
        string_literal4 = match( CREATE_INDEX, TOKENS_FOLLOWING_CREATE_INDEX_IN_create_index_117 )

        tree_for_string_literal4 = @adaptor.create_with_payload( string_literal4 )
        root_0 = @adaptor.become_root( tree_for_string_literal4, root_0 )

        __ID5__ = match( ID, TOKENS_FOLLOWING_ID_IN_create_index_120 )

        tree_for_ID5 = @adaptor.create_with_payload( __ID5__ )
        @adaptor.add_child( root_0, tree_for_ID5 )

        string_literal6 = match( T__16, TOKENS_FOLLOWING_T__16_IN_create_index_122 )
        __ID7__ = match( ID, TOKENS_FOLLOWING_ID_IN_create_index_125 )

        tree_for_ID7 = @adaptor.create_with_payload( __ID7__ )
        @adaptor.add_child( root_0, tree_for_ID7 )

        char_literal8 = match( T__17, TOKENS_FOLLOWING_T__17_IN_create_index_127 )
        __ID9__ = match( ID, TOKENS_FOLLOWING_ID_IN_create_index_130 )

        tree_for_ID9 = @adaptor.create_with_payload( __ID9__ )
        @adaptor.add_child( root_0, tree_for_ID9 )

        # at line 25:41: ( ',' ID )*
        while true # decision 3
          alt_3 = 2
          look_3_0 = @input.peek( 1 )

          if ( look_3_0 == T__18 )
            alt_3 = 1

          end
          case alt_3
          when 1
            # at line 25:42: ',' ID
            char_literal10 = match( T__18, TOKENS_FOLLOWING_T__18_IN_create_index_133 )
            __ID11__ = match( ID, TOKENS_FOLLOWING_ID_IN_create_index_136 )

            tree_for_ID11 = @adaptor.create_with_payload( __ID11__ )
            @adaptor.add_child( root_0, tree_for_ID11 )


          else
            break # out of loop for decision 3
          end
        end # loop for decision 3
        string_literal12 = match( T__19, TOKENS_FOLLOWING_T__19_IN_create_index_140 )
        # - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 3 )

      end
      
      return return_value
    end

    CreateTableReturnValue = define_return_scope 

    # 
    # parser rule create_table
    # 
    # (in data/SQL.g)
    # 27:1: create_table : 'create table' ID '(' create_table_def ( ',' create_table_def )* ');' ;
    # 
    def create_table
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 4 )
      return_value = CreateTableReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      string_literal13 = nil
      __ID14__ = nil
      char_literal15 = nil
      char_literal17 = nil
      string_literal19 = nil
      create_table_def16 = nil
      create_table_def18 = nil

      tree_for_string_literal13 = nil
      tree_for_ID14 = nil
      tree_for_char_literal15 = nil
      tree_for_char_literal17 = nil
      tree_for_string_literal19 = nil

      begin
        root_0 = @adaptor.create_flat_list


        # at line 28:5: 'create table' ID '(' create_table_def ( ',' create_table_def )* ');'
        string_literal13 = match( CREATE_TABLE, TOKENS_FOLLOWING_CREATE_TABLE_IN_create_table_151 )

        tree_for_string_literal13 = @adaptor.create_with_payload( string_literal13 )
        root_0 = @adaptor.become_root( tree_for_string_literal13, root_0 )

        __ID14__ = match( ID, TOKENS_FOLLOWING_ID_IN_create_table_154 )

        tree_for_ID14 = @adaptor.create_with_payload( __ID14__ )
        @adaptor.add_child( root_0, tree_for_ID14 )

        char_literal15 = match( T__17, TOKENS_FOLLOWING_T__17_IN_create_table_156 )
        @state.following.push( TOKENS_FOLLOWING_create_table_def_IN_create_table_159 )
        create_table_def16 = create_table_def
        @state.following.pop
        @adaptor.add_child( root_0, create_table_def16.tree )
        # at line 28:46: ( ',' create_table_def )*
        while true # decision 4
          alt_4 = 2
          look_4_0 = @input.peek( 1 )

          if ( look_4_0 == T__18 )
            alt_4 = 1

          end
          case alt_4
          when 1
            # at line 28:47: ',' create_table_def
            char_literal17 = match( T__18, TOKENS_FOLLOWING_T__18_IN_create_table_162 )
            @state.following.push( TOKENS_FOLLOWING_create_table_def_IN_create_table_165 )
            create_table_def18 = create_table_def
            @state.following.pop
            @adaptor.add_child( root_0, create_table_def18.tree )

          else
            break # out of loop for decision 4
          end
        end # loop for decision 4
        string_literal19 = match( T__19, TOKENS_FOLLOWING_T__19_IN_create_table_169 )
        # - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 4 )

      end
      
      return return_value
    end

    CreateTableDefReturnValue = define_return_scope 

    # 
    # parser rule create_table_def
    # 
    # (in data/SQL.g)
    # 30:1: create_table_def : ( column | pk_definition );
    # 
    def create_table_def
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 5 )
      return_value = CreateTableDefReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      column20 = nil
      pk_definition21 = nil


      begin
        # at line 31:3: ( column | pk_definition )
        alt_5 = 2
        look_5_0 = @input.peek( 1 )

        if ( look_5_0 == ID )
          alt_5 = 1
        elsif ( look_5_0 == PRIMARY_KEY )
          alt_5 = 2
        else
          raise NoViableAlternative( "", 5, 0 )
        end
        case alt_5
        when 1
          root_0 = @adaptor.create_flat_list


          # at line 31:5: column
          @state.following.push( TOKENS_FOLLOWING_column_IN_create_table_def_180 )
          column20 = column
          @state.following.pop
          @adaptor.add_child( root_0, column20.tree )

        when 2
          root_0 = @adaptor.create_flat_list


          # at line 32:5: pk_definition
          @state.following.push( TOKENS_FOLLOWING_pk_definition_IN_create_table_def_186 )
          pk_definition21 = pk_definition
          @state.following.pop
          @adaptor.add_child( root_0, pk_definition21.tree )

        end# - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 5 )

      end
      
      return return_value
    end

    ColumnReturnValue = define_return_scope 

    # 
    # parser rule column
    # 
    # (in data/SQL.g)
    # 34:1: column : ID datatype ( constraint )* ;
    # 
    def column
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 6 )
      return_value = ColumnReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      __ID22__ = nil
      datatype23 = nil
      constraint24 = nil

      tree_for_ID22 = nil

      begin
        root_0 = @adaptor.create_flat_list


        # at line 35:5: ID datatype ( constraint )*
        __ID22__ = match( ID, TOKENS_FOLLOWING_ID_IN_column_196 )

        tree_for_ID22 = @adaptor.create_with_payload( __ID22__ )
        root_0 = @adaptor.become_root( tree_for_ID22, root_0 )

        @state.following.push( TOKENS_FOLLOWING_datatype_IN_column_199 )
        datatype23 = datatype
        @state.following.pop
        @adaptor.add_child( root_0, datatype23.tree )
        # at line 35:18: ( constraint )*
        while true # decision 6
          alt_6 = 2
          look_6_0 = @input.peek( 1 )

          if ( look_6_0 == NOT_NULL )
            alt_6 = 1

          end
          case alt_6
          when 1
            # at line 35:18: constraint
            @state.following.push( TOKENS_FOLLOWING_constraint_IN_column_201 )
            constraint24 = constraint
            @state.following.pop
            @adaptor.add_child( root_0, constraint24.tree )

          else
            break # out of loop for decision 6
          end
        end # loop for decision 6
        # - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 6 )

      end
      
      return return_value
    end

    PkDefinitionReturnValue = define_return_scope 

    # 
    # parser rule pk_definition
    # 
    # (in data/SQL.g)
    # 37:1: pk_definition : 'primary key' '(' ID ( ',' ID )* ')' ;
    # 
    def pk_definition
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 7 )
      return_value = PkDefinitionReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      string_literal25 = nil
      char_literal26 = nil
      __ID27__ = nil
      char_literal28 = nil
      __ID29__ = nil
      char_literal30 = nil

      tree_for_string_literal25 = nil
      tree_for_char_literal26 = nil
      tree_for_ID27 = nil
      tree_for_char_literal28 = nil
      tree_for_ID29 = nil
      tree_for_char_literal30 = nil

      begin
        root_0 = @adaptor.create_flat_list


        # at line 38:5: 'primary key' '(' ID ( ',' ID )* ')'
        string_literal25 = match( PRIMARY_KEY, TOKENS_FOLLOWING_PRIMARY_KEY_IN_pk_definition_212 )

        tree_for_string_literal25 = @adaptor.create_with_payload( string_literal25 )
        root_0 = @adaptor.become_root( tree_for_string_literal25, root_0 )

        char_literal26 = match( T__17, TOKENS_FOLLOWING_T__17_IN_pk_definition_215 )
        __ID27__ = match( ID, TOKENS_FOLLOWING_ID_IN_pk_definition_218 )

        tree_for_ID27 = @adaptor.create_with_payload( __ID27__ )
        @adaptor.add_child( root_0, tree_for_ID27 )

        # at line 38:28: ( ',' ID )*
        while true # decision 7
          alt_7 = 2
          look_7_0 = @input.peek( 1 )

          if ( look_7_0 == T__18 )
            alt_7 = 1

          end
          case alt_7
          when 1
            # at line 38:29: ',' ID
            char_literal28 = match( T__18, TOKENS_FOLLOWING_T__18_IN_pk_definition_221 )
            __ID29__ = match( ID, TOKENS_FOLLOWING_ID_IN_pk_definition_224 )

            tree_for_ID29 = @adaptor.create_with_payload( __ID29__ )
            @adaptor.add_child( root_0, tree_for_ID29 )


          else
            break # out of loop for decision 7
          end
        end # loop for decision 7
        char_literal30 = match( T__20, TOKENS_FOLLOWING_T__20_IN_pk_definition_228 )
        # - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 7 )

      end
      
      return return_value
    end

    ConstraintReturnValue = define_return_scope 

    # 
    # parser rule constraint
    # 
    # (in data/SQL.g)
    # 40:1: constraint : 'not null' ;
    # 
    def constraint
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 8 )
      return_value = ConstraintReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      string_literal31 = nil

      tree_for_string_literal31 = nil

      begin
        root_0 = @adaptor.create_flat_list


        # at line 41:5: 'not null'
        string_literal31 = match( NOT_NULL, TOKENS_FOLLOWING_NOT_NULL_IN_constraint_239 )

        tree_for_string_literal31 = @adaptor.create_with_payload( string_literal31 )
        @adaptor.add_child( root_0, tree_for_string_literal31 )

        # - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 8 )

      end
      
      return return_value
    end

    DatatypeReturnValue = define_return_scope 

    # 
    # parser rule datatype
    # 
    # (in data/SQL.g)
    # 43:1: datatype : ( 'integer' | 'timestamp' | 'char' '(' INT ')' | 'varchar' '(' INT ')' | 'numeric' '(' INT ',' INT ')' );
    # 
    def datatype
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 9 )
      return_value = DatatypeReturnValue.new

      # $rule.start = the first token seen before matching
      return_value.start = @input.look

      root_0 = nil
      string_literal32 = nil
      string_literal33 = nil
      string_literal34 = nil
      char_literal35 = nil
      __INT36__ = nil
      char_literal37 = nil
      string_literal38 = nil
      char_literal39 = nil
      __INT40__ = nil
      char_literal41 = nil
      string_literal42 = nil
      char_literal43 = nil
      __INT44__ = nil
      char_literal45 = nil
      __INT46__ = nil
      char_literal47 = nil

      tree_for_string_literal32 = nil
      tree_for_string_literal33 = nil
      tree_for_string_literal34 = nil
      tree_for_char_literal35 = nil
      tree_for_INT36 = nil
      tree_for_char_literal37 = nil
      tree_for_string_literal38 = nil
      tree_for_char_literal39 = nil
      tree_for_INT40 = nil
      tree_for_char_literal41 = nil
      tree_for_string_literal42 = nil
      tree_for_char_literal43 = nil
      tree_for_INT44 = nil
      tree_for_char_literal45 = nil
      tree_for_INT46 = nil
      tree_for_char_literal47 = nil

      begin
        # at line 44:3: ( 'integer' | 'timestamp' | 'char' '(' INT ')' | 'varchar' '(' INT ')' | 'numeric' '(' INT ',' INT ')' )
        alt_8 = 5
        case look_8 = @input.peek( 1 )
        when INTEGER then alt_8 = 1
        when TIMESTAMP then alt_8 = 2
        when CHAR then alt_8 = 3
        when VARCHAR then alt_8 = 4
        when NUMERIC then alt_8 = 5
        else
          raise NoViableAlternative( "", 8, 0 )
        end
        case alt_8
        when 1
          root_0 = @adaptor.create_flat_list


          # at line 44:5: 'integer'
          string_literal32 = match( INTEGER, TOKENS_FOLLOWING_INTEGER_IN_datatype_249 )

          tree_for_string_literal32 = @adaptor.create_with_payload( string_literal32 )
          @adaptor.add_child( root_0, tree_for_string_literal32 )


        when 2
          root_0 = @adaptor.create_flat_list


          # at line 45:5: 'timestamp'
          string_literal33 = match( TIMESTAMP, TOKENS_FOLLOWING_TIMESTAMP_IN_datatype_255 )

          tree_for_string_literal33 = @adaptor.create_with_payload( string_literal33 )
          @adaptor.add_child( root_0, tree_for_string_literal33 )


        when 3
          root_0 = @adaptor.create_flat_list


          # at line 46:5: 'char' '(' INT ')'
          string_literal34 = match( CHAR, TOKENS_FOLLOWING_CHAR_IN_datatype_261 )

          tree_for_string_literal34 = @adaptor.create_with_payload( string_literal34 )
          root_0 = @adaptor.become_root( tree_for_string_literal34, root_0 )

          char_literal35 = match( T__17, TOKENS_FOLLOWING_T__17_IN_datatype_264 )
          __INT36__ = match( INT, TOKENS_FOLLOWING_INT_IN_datatype_267 )

          tree_for_INT36 = @adaptor.create_with_payload( __INT36__ )
          @adaptor.add_child( root_0, tree_for_INT36 )

          char_literal37 = match( T__20, TOKENS_FOLLOWING_T__20_IN_datatype_269 )

        when 4
          root_0 = @adaptor.create_flat_list


          # at line 47:5: 'varchar' '(' INT ')'
          string_literal38 = match( VARCHAR, TOKENS_FOLLOWING_VARCHAR_IN_datatype_276 )

          tree_for_string_literal38 = @adaptor.create_with_payload( string_literal38 )
          root_0 = @adaptor.become_root( tree_for_string_literal38, root_0 )

          char_literal39 = match( T__17, TOKENS_FOLLOWING_T__17_IN_datatype_279 )
          __INT40__ = match( INT, TOKENS_FOLLOWING_INT_IN_datatype_282 )

          tree_for_INT40 = @adaptor.create_with_payload( __INT40__ )
          @adaptor.add_child( root_0, tree_for_INT40 )

          char_literal41 = match( T__20, TOKENS_FOLLOWING_T__20_IN_datatype_284 )

        when 5
          root_0 = @adaptor.create_flat_list


          # at line 48:5: 'numeric' '(' INT ',' INT ')'
          string_literal42 = match( NUMERIC, TOKENS_FOLLOWING_NUMERIC_IN_datatype_291 )

          tree_for_string_literal42 = @adaptor.create_with_payload( string_literal42 )
          root_0 = @adaptor.become_root( tree_for_string_literal42, root_0 )

          char_literal43 = match( T__17, TOKENS_FOLLOWING_T__17_IN_datatype_294 )
          __INT44__ = match( INT, TOKENS_FOLLOWING_INT_IN_datatype_297 )

          tree_for_INT44 = @adaptor.create_with_payload( __INT44__ )
          @adaptor.add_child( root_0, tree_for_INT44 )

          char_literal45 = match( T__18, TOKENS_FOLLOWING_T__18_IN_datatype_299 )
          __INT46__ = match( INT, TOKENS_FOLLOWING_INT_IN_datatype_302 )

          tree_for_INT46 = @adaptor.create_with_payload( __INT46__ )
          @adaptor.add_child( root_0, tree_for_INT46 )

          char_literal47 = match( T__20, TOKENS_FOLLOWING_T__20_IN_datatype_304 )

        end# - - - - - - - rule clean up - - - - - - - -
        return_value.stop = @input.look( -1 )


        return_value.tree = @adaptor.rule_post_processing( root_0 )
        @adaptor.set_token_boundaries( return_value.tree, return_value.start, return_value.stop )

      rescue ANTLR3::Error::RecognitionError => re
        report_error(re)
        recover(re)
        return_value.tree = @adaptor.create_error_node( @input, return_value.start, @input.look(-1), re )

      ensure
        # -> uncomment the next line to manually enable rule tracing
        # trace_out( __method__, 9 )

      end
      
      return return_value
    end



    TOKENS_FOLLOWING_statement_IN_statements_90 = Set[ 1, 4, 5 ]
    TOKENS_FOLLOWING_create_table_IN_statement_101 = Set[ 1 ]
    TOKENS_FOLLOWING_create_index_IN_statement_107 = Set[ 1 ]
    TOKENS_FOLLOWING_CREATE_INDEX_IN_create_index_117 = Set[ 13 ]
    TOKENS_FOLLOWING_ID_IN_create_index_120 = Set[ 16 ]
    TOKENS_FOLLOWING_T__16_IN_create_index_122 = Set[ 13 ]
    TOKENS_FOLLOWING_ID_IN_create_index_125 = Set[ 17 ]
    TOKENS_FOLLOWING_T__17_IN_create_index_127 = Set[ 13 ]
    TOKENS_FOLLOWING_ID_IN_create_index_130 = Set[ 18, 19 ]
    TOKENS_FOLLOWING_T__18_IN_create_index_133 = Set[ 13 ]
    TOKENS_FOLLOWING_ID_IN_create_index_136 = Set[ 18, 19 ]
    TOKENS_FOLLOWING_T__19_IN_create_index_140 = Set[ 1 ]
    TOKENS_FOLLOWING_CREATE_TABLE_IN_create_table_151 = Set[ 13 ]
    TOKENS_FOLLOWING_ID_IN_create_table_154 = Set[ 17 ]
    TOKENS_FOLLOWING_T__17_IN_create_table_156 = Set[ 12, 13 ]
    TOKENS_FOLLOWING_create_table_def_IN_create_table_159 = Set[ 18, 19 ]
    TOKENS_FOLLOWING_T__18_IN_create_table_162 = Set[ 12, 13 ]
    TOKENS_FOLLOWING_create_table_def_IN_create_table_165 = Set[ 18, 19 ]
    TOKENS_FOLLOWING_T__19_IN_create_table_169 = Set[ 1 ]
    TOKENS_FOLLOWING_column_IN_create_table_def_180 = Set[ 1 ]
    TOKENS_FOLLOWING_pk_definition_IN_create_table_def_186 = Set[ 1 ]
    TOKENS_FOLLOWING_ID_IN_column_196 = Set[ 6, 7, 8, 9, 10 ]
    TOKENS_FOLLOWING_datatype_IN_column_199 = Set[ 1, 11 ]
    TOKENS_FOLLOWING_constraint_IN_column_201 = Set[ 1, 11 ]
    TOKENS_FOLLOWING_PRIMARY_KEY_IN_pk_definition_212 = Set[ 17 ]
    TOKENS_FOLLOWING_T__17_IN_pk_definition_215 = Set[ 13 ]
    TOKENS_FOLLOWING_ID_IN_pk_definition_218 = Set[ 18, 20 ]
    TOKENS_FOLLOWING_T__18_IN_pk_definition_221 = Set[ 13 ]
    TOKENS_FOLLOWING_ID_IN_pk_definition_224 = Set[ 18, 20 ]
    TOKENS_FOLLOWING_T__20_IN_pk_definition_228 = Set[ 1 ]
    TOKENS_FOLLOWING_NOT_NULL_IN_constraint_239 = Set[ 1 ]
    TOKENS_FOLLOWING_INTEGER_IN_datatype_249 = Set[ 1 ]
    TOKENS_FOLLOWING_TIMESTAMP_IN_datatype_255 = Set[ 1 ]
    TOKENS_FOLLOWING_CHAR_IN_datatype_261 = Set[ 17 ]
    TOKENS_FOLLOWING_T__17_IN_datatype_264 = Set[ 14 ]
    TOKENS_FOLLOWING_INT_IN_datatype_267 = Set[ 20 ]
    TOKENS_FOLLOWING_T__20_IN_datatype_269 = Set[ 1 ]
    TOKENS_FOLLOWING_VARCHAR_IN_datatype_276 = Set[ 17 ]
    TOKENS_FOLLOWING_T__17_IN_datatype_279 = Set[ 14 ]
    TOKENS_FOLLOWING_INT_IN_datatype_282 = Set[ 20 ]
    TOKENS_FOLLOWING_T__20_IN_datatype_284 = Set[ 1 ]
    TOKENS_FOLLOWING_NUMERIC_IN_datatype_291 = Set[ 17 ]
    TOKENS_FOLLOWING_T__17_IN_datatype_294 = Set[ 14 ]
    TOKENS_FOLLOWING_INT_IN_datatype_297 = Set[ 18 ]
    TOKENS_FOLLOWING_T__18_IN_datatype_299 = Set[ 14 ]
    TOKENS_FOLLOWING_INT_IN_datatype_302 = Set[ 20 ]
    TOKENS_FOLLOWING_T__20_IN_datatype_304 = Set[ 1 ]

  end # class Parser < ANTLR3::Parser

  at_exit { Parser.main( ARGV ) } if __FILE__ == $0
end

