CREATE TABLE [dbo].[GayCounter]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [username] NCHAR(10) NOT NULL, 
    [gayCount] INT NOT NULL DEFAULT 0, 
    [lastIncident] DATETIME NOT NULL
)
