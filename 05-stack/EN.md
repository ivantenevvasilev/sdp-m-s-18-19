# Week 5

As we've seen, the stack is an abstract data structure which can keep some quantity of data that is of the same type.

When an element is added to the stack, it's placed on its top and when we remove data it's removed from the same top (LIFO). It also provides a way to access the element on the top and can return whether or not the stack has any data in it.

This is said in a very broad sense and we can implement a Stack in many ways. We will implement one of them now.

## Exercise 1
Let's implement our own stack class `CharStack` which will be a stack of characters (`char`). We will keep the elements of the stack in an array of characters with a maximum size of, for example, 256.
We will also need an integer variable that will keep the position of the top of the stack.

We have to be able to create an empty stack. We will define the following functions:
```c++
char top() const;  // returns the element on the top of the stack
void push(const char c); // adds an element on top of the stack
char pop();  // removes an element from the stack and returns the value that was previously on the top
bool is_empty() const; // returns if the stack is empty
```
Of course, you can add other functions if you'd like and think they will help you for some other exercise.

## Exercise 2
Let's solve the task from last week:

We are given a rule for an expression of the following format:

```
<expression> ::= <digit> | f(<expression>,<expression>,<expression>) 
                         | g(<expression>,<expression>,<expression>)
<digit> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
```

where

```
f(x,y,z) = (x+2y+3z)%10
g(x,y,z) = (2x+3y+7z)%10
```

Define a function that takes as an argument an expression of the given format and calculates it.

### Example
| Input                    | Output |
| :----------------------- | ------ |
| "9"                      | 9      |
| "f(g(1,2,3),4,f(5,6,7))" | 1      |
| "f(1,g(2,3,4),f(5,6,7))" | 7      |

## Exercise 3
XML is a text format for data exchange. It is easyly parsed from computers as well as easily readable by people.

XML is defined by the so called tags, which are some name, surrounded by angular brackets.
There are two types of tags - opening, for example `<something>`, and closing - `</otherthing>`.
Between an opening and a closing tag with the same name there can be any kind of text, including other tags.
This way one tag can be a 'parent' of (meaning to contain) a number of other tags.

However, for a tag to be **correct** the XML has to have each parent be closed after every tag it contains is closed.
Also each tag has to be closed and to not have closing tags that do not correspond to an opening tag.

### Example
This is **not** _correct_ XML
```xml
<a>
   <b> <d>     whitespace doesn't matter       </d>
   </b> but makes things more readable
   <c>
                            </a> -- <a> is closed before <c>, but <a> contains <c>
   </c>
```

This also is **not** _correct_ XML
```xml
<a>
   <b> <d>     whitespace doesn't matter       </d>
   </b> but makes things more readable
   <c>
   </c>

-- <a> is never closed
```

This too is **not** _correct_ XML
```xml
<b></b>
</a>
```

This **is** _correct_ XML
```xml
<a>
   <b> <d>     whitespace doesn't matter       </d>
   </b> but makes things more readable
   <c>
   </c>
           </a>
```

For simplicity's sake, we will only be looking at XML, that contains tags with single-letter names and follows the rules mentioned above (in reality XML includes a lot more things, but they do not concern us)
Meaning we will only parse tags of the type `<a>` and `</a>`.

### The task
Define a function that accepts a string and returns a boolean value which indicates whether or not the string is a _correct_ XML.
_Note_: "some text without tags" is _correct_ XML by our definition.
