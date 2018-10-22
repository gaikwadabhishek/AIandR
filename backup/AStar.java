/*package a.star;*/

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

/**
 *
 */
public class AStar {

    static int Astargraph[][] = {{999, 4, 12, 8, 999, 999, 999}, {4, 999, 999, 999, 7, 999, 999}, {12, 999, 999, 999, 999, 999, 3}, {8, 999, 999, 999, 999, 2, 999}, {999, 7, 999, 999, 999, 999, 5}, {999, 999, 999, 2, 999, 999, 10}, {999, 999, 3, 999, 5, 10, 999}};
    static int weightOfVertices[] = {0, 4, 3, 5, 3, 2, 0};
    static Scanner sc = new Scanner(System.in);
    static Stack<Integer> visitingNodes = new Stack<>();
    static HashMap<Integer,String> mapTable = new HashMap <Integer,String>();
    
    static int source;
    static int dest;
    static int bestPathCost;
    static String bestPath;

    public static void main(String[] args) {
        System.out.println("Enter Source Node: ");
        source = sc.nextLine().charAt(0) - 65;

        System.out.println("Enter Destination Node: ");
        dest = sc.nextLine().charAt(0) - 65;
        
        findPath(source, dest);
        
        for(Map.Entry<Integer,String> e : mapTable.entrySet()){
            if(e.getKey() <= bestPathCost){
                bestPathCost = e.getKey();
                bestPath = e.getValue();
            }
        }
        
        System.out.println("Best Path:" + bestPath + " Cost: " + bestPathCost);
    }

    public static void findPath(int vertex, int dst) {
        if (vertex == dst) {
            System.out.print("Path: " + printPath());
            System.out.println("  Cost: " + findCost());
            return;
        }
        visitingNodes.push(vertex);
        for (int n = 0; n < Astargraph.length; n++) {
            if (Astargraph[vertex][n] != 999 && checkForPrevious(n)) {
                /*if(n == dst){
                 System.out.println("Path:" + vertex + "-->" + dst);
                 return;
                 }*/
                findPath(n, dst);
            }
        }
        visitingNodes.pop();
    }

    private static boolean checkForPrevious(int key) {
        if (visitingNodes.contains(key)) {
            return false;
        }
        return true;
    }

    private static String printPath() {
        String path = "";
        for (Integer visitingNode : visitingNodes) {
            char c = (char) (visitingNode + 65);
            path += "  " + c + "  -->";
        }
        path += "  " + ((char)(dest+65));
        return path;
    }

    private static int findCost() {
        int sum = 0;
        for (int i = 0; i < visitingNodes.size() - 1; i++) {
            sum += weightOfVertices[visitingNodes.get(i)] + Astargraph[visitingNodes.get(i)][visitingNodes.get(i+1)];
        }
        sum += weightOfVertices[visitingNodes.peek()] + Astargraph[visitingNodes.peek()][dest] + weightOfVertices[dest];
        bestPathCost = sum;
        mapTable.put(sum, printPath());
        return sum;
    }

}
