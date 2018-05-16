Lukas Arnold, Patrick Bucher

# Abschlussfragen

1. Was ist eine Solaris-Zone?

Eine virtuelle Betriebssystem-Umgebung innerhalb eines Solaris-Betriebssystems.

2. Wo sehen Sie mögliche Einsatzszenarien für Solaris-Zonen?

Wenn viele Systeme benötigt werden, die gemeinsam nur so viele Ressourcen
brauchen, wie sie das Host-System zur Verfügung stellt.

3. Was sehen Sie für Vorteile von Solaris-Zonen?

Sie können schnell erstellt und wieder entfernt werden; man kann die Ressourcen
des Systems per Einstellungen beschränken; sie können einfach auf ein anderes
System übertragen werden.

4. Wo sehen Sie Nachteile für Solaris-Zonen?

Es gibt zwei Fehlerquellen: das Host- und das Gast-System, und man weiss
vielleicht nicht, auf welchem System ein Problem vorliegt.

5. Nennen Sie drei weitere Konfigurationen, die nicht in dieser Übung verwendet
wurden, welche Sie mit `zonecfg` konfigurieren können und erklären Sie diese
kurz.

- Migration: eine Zone kann auf ein anderes System migriert werden
- Zurücksetzen: eine angepasste Einstellung kann auf die Standard-Einstellung
  zurückgesetzt werden
- Umbenennen: einer Zone kann ein anderer Name vergeben werden

6. Was haben Sie persönlich in dieser Übung gelernt?

- Dass das erstellen der ersten Zone aufwändig ist, man danach aber diese
  einfach klonen kann und es dann schneller geht.
- Wie man mit Solaris neue Zonen erstellt.
- Wie man die Ressourcen (Memory) einer Zone einschränkt.
- Dass es für den Benutzer transparent ist, ob er auf einem virtuellen oder auf
  einem Host-System arbeitet.
