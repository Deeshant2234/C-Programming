#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define NUM_CLUSTERS 3
#define NUM_POINTS 10

typedef struct {
    double x;
    double y;
} Point;

void initialize_centroids(Point centroids[], Point points[], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        centroids[i] = points[i];
    }
}

double calculate_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int find_closest_centroid(Point point, Point centroids[], int num_clusters) {
    double min_distance = calculate_distance(point, centroids[0]);
    int closest_centroid = 0;

    for (int i = 1; i < num_clusters; i++) {
        double distance = calculate_distance(point, centroids[i]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_centroid = i;
        }
    }

    return closest_centroid;
}

void update_centroids(Point centroids[], Point points[], int assignments[], int num_clusters, int num_points) {
    int counts[NUM_CLUSTERS] = {0};
    Point sums[NUM_CLUSTERS] = {0};

    for (int i = 0; i < num_points; i++) {
        int cluster = assignments[i];
        sums[cluster].x += points[i].x;
        sums[cluster].y += points[i].y;
        counts[cluster]++;
    }

    for (int i = 0; i < num_clusters; i++) {
        if (counts[i] > 0) {
            centroids[i].x = sums[i].x / counts[i];
            centroids[i].y = sums[i].y / counts[i];
        }
    }
}

void kmeans(Point points[], int num_points, int num_clusters) {
    Point centroids[NUM_CLUSTERS];
    int assignments[NUM_POINTS];
    int iterations = 0;

    initialize_centroids(centroids, points, num_clusters);

    while (iterations < MAX_ITERATIONS) {
        int changes = 0;

        for (int i = 0; i < num_points; i++) {
            int closest_centroid = find_closest_centroid(points[i], centroids, num_clusters);
            if (assignments[i] != closest_centroid) {
                assignments[i] = closest_centroid;
                changes++;
            }
        }

        if (changes == 0) {
            break;
        }

        update_centroids(centroids, points, assignments, num_clusters, num_points);
        iterations++;
    }

    printf("Final centroids:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Centroid %d: (%.2f, %.2f)\n", i, centroids[i].x, centroids[i].y);
    }
}

int main() {
    Point points[NUM_POINTS] = {
        {1.0, 1.0}, {1.5, 2.0}, {3.0, 4.0},
        {5.0, 7.0}, {3.5, 5.0}, {4.5, 5.0},
        {3.5, 4.5}, {2.0, 2.0}, {6.0, 8.0},
        {7.0, 9.0}
    };

    kmeans(points, NUM_POINTS, NUM_CLUSTERS);

    return 0;
}