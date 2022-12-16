

# kb (kanban board in your terminal) #

## Usage: ##

Create board if it doesn't exist and show board if it exists  
`kb myboard`

Add column  
`kb myboard -c col1`

Add task to column  
`kb myboard -t task1 col1`

Move task to column  
`kb myboard task1 -m col1`

Assign task to assignee  
`kb myboard task1 -a assignee1`

Set task priority  
`kb myboard task1 -p [normal | high]`

Set task description  
`kb myboard task1 -d "some description"`

Show task  
`kb myboard task1`