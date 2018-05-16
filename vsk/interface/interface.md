---
title: Logger-Interface
subtitle: Verteilte Systeme und Komponenten
author:
    - Parick Bucher
    - Patrick Mangold
    - Lucien Zürcher
date: \today
---

# Interfaces

## `LoggerSetup`

```java
public interface LoggerSetup {
    public Logger connect(String host, int portNumber)
        throws java.net.ConnectException;
}
```

## `Logger`

```java
public interface Logger {
    public void log(Level level, String message);
    public void setLevel(Level level);
}
```
## `Level`

```java
public enum Level {
    TRACE,DEBUG,INFO,WARN,ERROR,FATAL
}
```

# Beispiel 

## Implementierung `LoggerSetup`

```java
public class LocalLoggerSetup implements LoggerSetup {
    public Logger connect(String host, int portNumber)
        throws ConnectException {
        return new LocalLogger();
    }
}
```

## Implementierung `Logger`

```java
public class LocalLogger implements Logger {
    private Level level = Level.TRACE;
    public void log(Level level, String message) {
        if (level.ordinal() >= this.level.ordinal()) {
            LocalDateTime now = LocalDateTime.now();
            String log = String.format("%s [%s]\t%s",
                    now, level.name(), message);
            System.out.println(log);
        }
    }
    public void setLevel(Level level) {
        this.level = level;
    }
}
```

## Verwendung

```java
try {
    LoggerSetup setup = new LocalLoggerSetup();
    Logger logger = setup.connect("127.0.0.1", 1337);
    logger.log(Level.TRACE, "cell spawned");
    logger.log(Level.DEBUG, "user activated cell");
    logger.log(Level.INFO, "user reset the grid");
    logger.log(Level.WARN, "game is stuck");
    logger.log(Level.ERROR, "IOException");
    logger.log(Level.FATAL, "Cthulhu awoke");
} catch (ConnectException connectException) {
    connectException.printStackTrace();
}
```

## Ausgabe

    2018-03-03T10:08:42.626710 [TRACE]  cell spawned
    2018-03-03T10:08:42.644668 [DEBUG]  user activated cell
    2018-03-03T10:08:42.644864 [INFO]   user reset the grid
    2018-03-03T10:08:42.645038 [WARN]   game is stuck
    2018-03-03T10:08:42.645202 [ERROR]  IOException
    2018-03-03T10:08:42.645365 [FATAL]  Cthulhu awoke

# Weitere Überlegungen

## Identifizierung der Session

- Abhängig von der Implementierung
- Mögliche Identifier:
    - IP + Portnummer (identifiziert Client)
    - zufällige UUID (identifiziert Session)
    - Kombination (identifiziert Client & Session)

## Verbindungsaufnahme

- Interface rein clienseitig
    - Game zu lokaler Logger-Komponente
    - _nicht_ Client zu Server
- Verbindungsaufnahme könnte «lazy» erfolgen
    - nicht bei `connect()`
    - sondern beim ersten `log()`-Aufruf
    - `log()` müsste eine `Exception` werfen

# Fragen? Diskussion
