noinst_LIBRARIES=libjson.a
INCLUDE=$(top_srcdir)/include/redbud
AM_CPPFLAGS=-std=c++11 -I$(top_srcdir)/include -static
libjson_a_SOURCES=exception.cc\
				  json.cc\
				  json_parser.cc\
				  reader.cc\
				  $(INCLUDE)/exception.h\
				  $(INCLUDE)/noncopyable.h\
				  $(INCLUDE)/platform.h\
				  $(INCLUDE)/tokenizer.h\
				  $(INCLUDE)/parser/json.h\
				  $(INCLUDE)/parser/json_parser.h\
				  $(INCLUDE)/parser/reader.h\
				  $(INCLUDE)/parser/tokenizer.h
