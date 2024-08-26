declare module "*nodestreamer.node" {
    class Converter {
        constructor(source?: string, destination?: string);
        start(): void;
        set_source(source: string): boolean;
        set_destination(destination: string): boolean;
    }
}