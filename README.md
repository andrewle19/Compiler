<h2>Author: Andrew Le</h2>
<h2>Email:andrewle19@gmail.com</h2>
<p>Compiler project that takes in an original grammar parses and converts the grammar into Backus–Naur form(BNF).
This grammar can include mathematical operands, named variables and print statements.
Uses a predictive parsing table to check if the grammar is valid.
Converts the grammar into valid python/c++ code.
<b>NOTE: </b>A real compiler will convert to machine code instead we simulate the process with high level code)</p>

<h3> Original Grammar RailRoad</h3>
| <prog>          | PROGRAM <identifier>; <dec-list> BEGIN <stat-list> END. |
|-----------------|---------------------------------------------------------|
| <identifier>    | <id><more-id-digit>                                     |
| <more-id-digit> | <digit><more-id-digit> | <id><more-id-digit> | blank    |
| <dec-list>      | <type>:<dec>;                                           |
| <dec>           | <identifier>,<dec> | <identifier>                       |
| <type>          | INTEGER                                                 |
| <stat-list>     | <stat>|<stat><stat-list>                                |
| <print>         | PRINT(<identifer>);                                     |
| <assign>        | <identifier>=<expr>;                                    |
| <expr>          | <term>+<expr> | <term>-<expr> | <term>                  |
| <term>          | <term>*<factor> | <term>/<factor> | <factor>            |
| <factor>        | <identifier> | <number> | (<expr>)                      |
| <number>        | <sign><digit><more-digit>                               |
| <sign>          | +|-|blank                                               |
| <more-digit>    | <digit><more-digit> | blank                             |
| <digit>         | 0|1|2|3|4|5|6|7|8|9                                     |
| <id>            | P|Q|R|S                                                 |
