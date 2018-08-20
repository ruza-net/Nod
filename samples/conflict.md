# General code style conflicts
## Functional vs. Shorthand Imperative

Nod was designed to combine the nice syntax of Swift,
and the generality and rigor of Haskell. It ought to combine
the best of both imperative and functional paradigms.

But there arises a conflict inherent from the nature of
both approaches. The Swift syntax features many shorthands for
`Optional` unwrapping, for example. But this is in conflict with
the Haskell way of doing things, namely by function application
and composition, and by higher-order function passing
(e.g. Functor mapping).

**TODO: _`del` and `del?`_**

## Functional vs. Traditional Object-Oriented

The next question is about the object model I want to implement.
Take this example:

```nod
class Person {
    func greet() -> String {
        return "Hello world!"
    }
}

let bob = Optional.Some(Person())
```

What would be the way of safely unwrapping the `Optional` and
calling the method `greet`?

Like Swift:

```nod
bob?.greet()

// or

if (let bob = bob) {
    bob.greet()
}
```

... like this:

```nod
bob.greet()

//    Gets transformed to functorial function
// which returns `Optional`. This function is
// passed to the `Optional<Person>` as a message
// (Smalltalk style), so it can be treated like
// an ordinary higher-order function.
```

... or like Haskell:

```nod
{ $0.greet() } <- bob
```

I personally like both the Swift way and Haskell way -
the Swift one for simplicity, and the Haskell one for
predictability and for revealing the underlying logic.
