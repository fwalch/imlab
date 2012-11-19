#!/usr/bin/env ruby
#
# data/SQL.g
# --
# Generated using ANTLR version: 3.2.1-SNAPSHOT Jul 31, 2010 19:34:52
# Ruby runtime library version: 1.8.11
# Input grammar file: data/SQL.g
# Generated at: 2012-11-19 21:16:55
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
    define_tokens( :INTEGER => 6, :T__19 => 19, :CREATE_INDEX => 5, :T__16 => 16, 
                   :WS => 15, :T__18 => 18, :T__17 => 17, :CREATE_TABLE => 4, 
                   :PRIMARY_KEY => 12, :T__20 => 20, :CHAR => 8, :VARCHAR => 7, 
                   :INT => 14, :NUMERIC => 9, :ID => 13, :EOF => -1, :TIMESTAMP => 10, 
                   :NOT_NULL => 11 )
    
  end


  class Lexer < ANTLR3::Lexer
    @grammar_home = SQL
    include TokenData

    
    begin
      generated_using( "data/SQL.g", "3.2.1-SNAPSHOT Jul 31, 2010 19:34:52", "1.8.11" )
    rescue NoMethodError => error
      # ignore
    end
    
    RULE_NAMES   = [ "CREATE_TABLE", "CREATE_INDEX", "INTEGER", "VARCHAR", 
                     "CHAR", "NUMERIC", "TIMESTAMP", "NOT_NULL", "PRIMARY_KEY", 
                     "T__16", "T__17", "T__18", "T__19", "T__20", "ID", 
                     "INT", "WS" ].freeze
    RULE_METHODS = [ :create_table!, :create_index!, :integer!, :varchar!, 
                     :char!, :numeric!, :timestamp!, :not_null!, :primary_key!, 
                     :t__16!, :t__17!, :t__18!, :t__19!, :t__20!, :id!, 
                     :int!, :ws! ].freeze

    
    def initialize( input=nil, options = {} )
      super( input, options )

    end
    
    
    # - - - - - - - - - - - lexer rules - - - - - - - - - - - -
    # lexer rule create_table! (CREATE_TABLE)
    # (in data/SQL.g)
    def create_table!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 1 )

      type = CREATE_TABLE
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 3:16: 'create table'
      match( "create table" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 1 )

    end

    # lexer rule create_index! (CREATE_INDEX)
    # (in data/SQL.g)
    def create_index!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 2 )

      type = CREATE_INDEX
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 4:16: 'create index'
      match( "create index" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 2 )

    end

    # lexer rule integer! (INTEGER)
    # (in data/SQL.g)
    def integer!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 3 )

      type = INTEGER
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 5:11: 'integer'
      match( "integer" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 3 )

    end

    # lexer rule varchar! (VARCHAR)
    # (in data/SQL.g)
    def varchar!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 4 )

      type = VARCHAR
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 6:11: 'varchar'
      match( "varchar" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 4 )

    end

    # lexer rule char! (CHAR)
    # (in data/SQL.g)
    def char!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 5 )

      type = CHAR
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 7:8: 'char'
      match( "char" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 5 )

    end

    # lexer rule numeric! (NUMERIC)
    # (in data/SQL.g)
    def numeric!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 6 )

      type = NUMERIC
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 8:11: 'numeric'
      match( "numeric" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 6 )

    end

    # lexer rule timestamp! (TIMESTAMP)
    # (in data/SQL.g)
    def timestamp!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 7 )

      type = TIMESTAMP
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 9:13: 'timestamp'
      match( "timestamp" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 7 )

    end

    # lexer rule not_null! (NOT_NULL)
    # (in data/SQL.g)
    def not_null!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 8 )

      type = NOT_NULL
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 10:12: 'not null'
      match( "not null" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 8 )

    end

    # lexer rule primary_key! (PRIMARY_KEY)
    # (in data/SQL.g)
    def primary_key!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 9 )

      type = PRIMARY_KEY
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 11:15: 'primary key'
      match( "primary key" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 9 )

    end

    # lexer rule t__16! (T__16)
    # (in data/SQL.g)
    def t__16!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 10 )

      type = T__16
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 12:9: 'on'
      match( "on" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 10 )

    end

    # lexer rule t__17! (T__17)
    # (in data/SQL.g)
    def t__17!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 11 )

      type = T__17
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 13:9: '('
      match( 0x28 )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 11 )

    end

    # lexer rule t__18! (T__18)
    # (in data/SQL.g)
    def t__18!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 12 )

      type = T__18
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 14:9: ','
      match( 0x2c )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 12 )

    end

    # lexer rule t__19! (T__19)
    # (in data/SQL.g)
    def t__19!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 13 )

      type = T__19
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 15:9: ');'
      match( ");" )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 13 )

    end

    # lexer rule t__20! (T__20)
    # (in data/SQL.g)
    def t__20!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 14 )

      type = T__20
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 16:9: ')'
      match( 0x29 )

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 14 )

    end

    # lexer rule id! (ID)
    # (in data/SQL.g)
    def id!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 15 )

      type = ID
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 51:5: ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )*
      if @input.peek( 1 ).between?( 0x41, 0x5a ) || @input.peek(1) == 0x5f || @input.peek( 1 ).between?( 0x61, 0x7a )
        @input.consume
      else
        mse = MismatchedSet( nil )
        recover mse
        raise mse
      end


      # at line 51:29: ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )*
      while true # decision 1
        alt_1 = 2
        look_1_0 = @input.peek( 1 )

        if ( look_1_0.between?( 0x30, 0x39 ) || look_1_0.between?( 0x41, 0x5a ) || look_1_0 == 0x5f || look_1_0.between?( 0x61, 0x7a ) )
          alt_1 = 1

        end
        case alt_1
        when 1
          # at line 
          if @input.peek( 1 ).between?( 0x30, 0x39 ) || @input.peek( 1 ).between?( 0x41, 0x5a ) || @input.peek(1) == 0x5f || @input.peek( 1 ).between?( 0x61, 0x7a )
            @input.consume
          else
            mse = MismatchedSet( nil )
            recover mse
            raise mse
          end



        else
          break # out of loop for decision 1
        end
      end # loop for decision 1

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 15 )

    end

    # lexer rule int! (INT)
    # (in data/SQL.g)
    def int!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 16 )

      type = INT
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 54:5: ( '0' .. '9' )+
      # at file 54:5: ( '0' .. '9' )+
      match_count_2 = 0
      while true
        alt_2 = 2
        look_2_0 = @input.peek( 1 )

        if ( look_2_0.between?( 0x30, 0x39 ) )
          alt_2 = 1

        end
        case alt_2
        when 1
          # at line 54:5: '0' .. '9'
          match_range( 0x30, 0x39 )

        else
          match_count_2 > 0 and break
          eee = EarlyExit(2)


          raise eee
        end
        match_count_2 += 1
      end


      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 16 )

    end

    # lexer rule ws! (WS)
    # (in data/SQL.g)
    def ws!
      # -> uncomment the next line to manually enable rule tracing
      # trace_in( __method__, 17 )

      type = WS
      channel = ANTLR3::DEFAULT_CHANNEL

      
      # - - - - main rule block - - - -
      # at line 57:5: ( ' ' | '\\r' | '\\n' | '\\t' | '\"' | '\\'' )
      if @input.peek( 1 ).between?( 0x9, 0xa ) || @input.peek(1) == 0xd || @input.peek(1) == 0x20 || @input.peek(1) == 0x22 || @input.peek(1) == 0x27
        @input.consume
      else
        mse = MismatchedSet( nil )
        recover mse
        raise mse
      end


      # --> action
       channel=HIDDEN; 
      # <-- action

      
      @state.type = type
      @state.channel = channel

    ensure
      # -> uncomment the next line to manually enable rule tracing
      # trace_out( __method__, 17 )

    end

    # main rule used to study the input at the current position,
    # and choose the proper lexer rule to call in order to
    # fetch the next token
    # 
    # usually, you don't make direct calls to this method,
    # but instead use the next_token method, which will
    # build and emit the actual next token
    def token!
      # at line 1:8: ( CREATE_TABLE | CREATE_INDEX | INTEGER | VARCHAR | CHAR | NUMERIC | TIMESTAMP | NOT_NULL | PRIMARY_KEY | T__16 | T__17 | T__18 | T__19 | T__20 | ID | INT | WS )
      alt_3 = 17
      alt_3 = @dfa3.predict( @input )
      case alt_3
      when 1
        # at line 1:10: CREATE_TABLE
        create_table!

      when 2
        # at line 1:23: CREATE_INDEX
        create_index!

      when 3
        # at line 1:36: INTEGER
        integer!

      when 4
        # at line 1:44: VARCHAR
        varchar!

      when 5
        # at line 1:52: CHAR
        char!

      when 6
        # at line 1:57: NUMERIC
        numeric!

      when 7
        # at line 1:65: TIMESTAMP
        timestamp!

      when 8
        # at line 1:75: NOT_NULL
        not_null!

      when 9
        # at line 1:84: PRIMARY_KEY
        primary_key!

      when 10
        # at line 1:96: T__16
        t__16!

      when 11
        # at line 1:102: T__17
        t__17!

      when 12
        # at line 1:108: T__18
        t__18!

      when 13
        # at line 1:114: T__19
        t__19!

      when 14
        # at line 1:120: T__20
        t__20!

      when 15
        # at line 1:126: ID
        id!

      when 16
        # at line 1:129: INT
        int!

      when 17
        # at line 1:133: WS
        ws!

      end
    end

    
    # - - - - - - - - - - DFA definitions - - - - - - - - - - -
    class DFA3 < ANTLR3::DFA
      EOT = unpack( 1, -1, 7, 11, 2, -1, 1, 24, 3, -1, 8, 11, 1, 33, 2, 
                    -1, 8, 11, 1, -1, 1, 11, 1, 43, 3, 11, 1, -1, 3, 11, 
                    1, -1, 11, 11, 1, -1, 1, 63, 1, 64, 1, 65, 2, 11, 5, 
                    -1, 1, 11, 1, -1, 1, 69, 1, -1 )
      EOF = unpack( 70, -1 )
      MIN = unpack( 1, 9, 1, 104, 1, 110, 1, 97, 1, 111, 1, 105, 1, 114, 
                    1, 110, 2, -1, 1, 59, 3, -1, 1, 101, 1, 97, 1, 116, 
                    1, 114, 1, 109, 1, 116, 1, 109, 1, 105, 1, 48, 2, -1, 
                    1, 97, 1, 114, 1, 101, 1, 99, 1, 101, 1, 32, 1, 101, 
                    1, 109, 1, -1, 1, 116, 1, 48, 1, 103, 1, 104, 1, 114, 
                    1, -1, 1, 115, 1, 97, 1, 101, 1, -1, 1, 101, 1, 97, 
                    1, 105, 1, 116, 1, 114, 1, 32, 2, 114, 1, 99, 1, 97, 
                    1, 121, 1, 105, 3, 48, 1, 109, 1, 32, 5, -1, 1, 112, 
                    1, -1, 1, 48, 1, -1 )
      MAX = unpack( 1, 122, 1, 114, 1, 110, 1, 97, 1, 117, 1, 105, 1, 114, 
                    1, 110, 2, -1, 1, 59, 3, -1, 1, 101, 1, 97, 1, 116, 
                    1, 114, 1, 109, 1, 116, 1, 109, 1, 105, 1, 122, 2, -1, 
                    1, 97, 1, 114, 1, 101, 1, 99, 1, 101, 1, 32, 1, 101, 
                    1, 109, 1, -1, 1, 116, 1, 122, 1, 103, 1, 104, 1, 114, 
                    1, -1, 1, 115, 1, 97, 1, 101, 1, -1, 1, 101, 1, 97, 
                    1, 105, 1, 116, 1, 114, 1, 32, 2, 114, 1, 99, 1, 97, 
                    1, 121, 1, 116, 3, 122, 1, 109, 1, 32, 5, -1, 1, 112, 
                    1, -1, 1, 122, 1, -1 )
      ACCEPT = unpack( 8, -1, 1, 11, 1, 12, 1, -1, 1, 15, 1, 16, 1, 17, 
                       9, -1, 1, 13, 1, 14, 8, -1, 1, 10, 5, -1, 1, 8, 3, 
                       -1, 1, 5, 17, -1, 1, 1, 1, 2, 1, 3, 1, 4, 1, 6, 1, 
                       -1, 1, 9, 1, -1, 1, 7 )
      SPECIAL = unpack( 70, -1 )
      TRANSITION = [
        unpack( 2, 13, 2, -1, 1, 13, 18, -1, 1, 13, 1, -1, 1, 13, 4, -1, 
                1, 13, 1, 8, 1, 10, 2, -1, 1, 9, 3, -1, 10, 12, 7, -1, 26, 
                11, 4, -1, 1, 11, 1, -1, 2, 11, 1, 1, 5, 11, 1, 2, 4, 11, 
                1, 4, 1, 7, 1, 6, 3, 11, 1, 5, 1, 11, 1, 3, 4, 11 ),
        unpack( 1, 15, 9, -1, 1, 14 ),
        unpack( 1, 16 ),
        unpack( 1, 17 ),
        unpack( 1, 19, 5, -1, 1, 18 ),
        unpack( 1, 20 ),
        unpack( 1, 21 ),
        unpack( 1, 22 ),
        unpack(  ),
        unpack(  ),
        unpack( 1, 23 ),
        unpack(  ),
        unpack(  ),
        unpack(  ),
        unpack( 1, 25 ),
        unpack( 1, 26 ),
        unpack( 1, 27 ),
        unpack( 1, 28 ),
        unpack( 1, 29 ),
        unpack( 1, 30 ),
        unpack( 1, 31 ),
        unpack( 1, 32 ),
        unpack( 10, 11, 7, -1, 26, 11, 4, -1, 1, 11, 1, -1, 26, 11 ),
        unpack(  ),
        unpack(  ),
        unpack( 1, 34 ),
        unpack( 1, 35 ),
        unpack( 1, 36 ),
        unpack( 1, 37 ),
        unpack( 1, 38 ),
        unpack( 1, 39 ),
        unpack( 1, 40 ),
        unpack( 1, 41 ),
        unpack(  ),
        unpack( 1, 42 ),
        unpack( 10, 11, 7, -1, 26, 11, 4, -1, 1, 11, 1, -1, 26, 11 ),
        unpack( 1, 44 ),
        unpack( 1, 45 ),
        unpack( 1, 46 ),
        unpack(  ),
        unpack( 1, 47 ),
        unpack( 1, 48 ),
        unpack( 1, 49 ),
        unpack(  ),
        unpack( 1, 50 ),
        unpack( 1, 51 ),
        unpack( 1, 52 ),
        unpack( 1, 53 ),
        unpack( 1, 54 ),
        unpack( 1, 55 ),
        unpack( 1, 56 ),
        unpack( 1, 57 ),
        unpack( 1, 58 ),
        unpack( 1, 59 ),
        unpack( 1, 60 ),
        unpack( 1, 62, 10, -1, 1, 61 ),
        unpack( 10, 11, 7, -1, 26, 11, 4, -1, 1, 11, 1, -1, 26, 11 ),
        unpack( 10, 11, 7, -1, 26, 11, 4, -1, 1, 11, 1, -1, 26, 11 ),
        unpack( 10, 11, 7, -1, 26, 11, 4, -1, 1, 11, 1, -1, 26, 11 ),
        unpack( 1, 66 ),
        unpack( 1, 67 ),
        unpack(  ),
        unpack(  ),
        unpack(  ),
        unpack(  ),
        unpack(  ),
        unpack( 1, 68 ),
        unpack(  ),
        unpack( 10, 11, 7, -1, 26, 11, 4, -1, 1, 11, 1, -1, 26, 11 ),
        unpack(  )
      ].freeze
      
      ( 0 ... MIN.length ).zip( MIN, MAX ) do | i, a, z |
        if a > 0 and z < 0
          MAX[ i ] %= 0x10000
        end
      end
      
      @decision = 3
      

      def description
        <<-'__dfa_description__'.strip!
          1:1: Tokens : ( CREATE_TABLE | CREATE_INDEX | INTEGER | VARCHAR | CHAR | NUMERIC | TIMESTAMP | NOT_NULL | PRIMARY_KEY | T__16 | T__17 | T__18 | T__19 | T__20 | ID | INT | WS );
        __dfa_description__
      end
    end

    
    private
    
    def initialize_dfas
      super rescue nil
      @dfa3 = DFA3.new( self, 3 )

    end
  end # class Lexer < ANTLR3::Lexer

  at_exit { Lexer.main( ARGV ) } if __FILE__ == $0
end

