public class RaceSimulation {
public static void main (String [] args) {
RaceTrack track = new RaceTrack();
Runner runner1 = new Runner(track, "Alice", 10);
Runner runner2 = new Runner(track, "Eddie", 15);
Runner runner3 = new Runner(track, "Marie", 12);
runner1.start();
runner2.start();
runner3.start();
}
}
