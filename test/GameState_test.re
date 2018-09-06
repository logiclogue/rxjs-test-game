open GameState;
open Mocha;
open Chai;

describe("GameState", () => {
    describe(".tick()", () => {
        context("given player moving forward", () => {
            let player = Stubs.forward_entity;
            let input = GameState.{
                player,
                entities: []
            };
            let expected = GameState.{
                player: Entity.tick(player),
                entities: []
            };
            let result = tick(input);

            it("ticks that player", () => {
                expect(result)->t->deep->equal(expected);
            });
        });
    });
});
