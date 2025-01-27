<?php

// Testing object declarations in a file with a namespace.

namespace Yoast\Plugin;

/*
 * All OK.
 */
class Admin {}
class Class_Name {}
class Three_Part_Name {}

interface My_Interface_Name {}
trait Some_Trait_Name {}

/*
 * Too long.
 */

class Too_Long_Class_Name {} // Error.
interface This_Interface_Name_Is_Too_Long {} // Error.
trait Trait_Name_Is_Too_Long {} // Error.

/*
 * Custom settings.
 */

// phpcs:set Yoast.NamingConventions.ObjectNameDepth max_words 5
// phpcs:set Yoast.NamingConventions.ObjectNameDepth recommended_max_words 2

class Three_Part_Name {} // Warning.
class Six_Part_Class_Name_Too_Long {} // Error.

/*
 * Incorrect custom settings (soft > max).
 */

// phpcs:set Yoast.NamingConventions.ObjectNameDepth max_words 2
// phpcs:set Yoast.NamingConventions.ObjectNameDepth recommended_max_words 5

class Three_Part_ClassName {} // Error.
class Seven_Part_Class_Name_Too_Long_Too {} // Error.

// Reset to default settings.
// phpcs:set Yoast.NamingConventions.ObjectNameDepth max_words 3
// phpcs:set Yoast.NamingConventions.ObjectNameDepth recommended_max_words 3

/*
 * Ignore deprecated objects.
 */

/**
 * Class description, no @deprecated tag.
 *
 * @since x.x.x
 */
class Active_Class_With_Too_Long_Class_Name {} // Error.

/**
 * Class description.
 *
 * @deprecated x.x.x
 */
class Deprecated_Class_With_Too_Long_Class_Name {} // OK.

/**
 * Class description, no @deprecated tag.
 *
 * @since x.x.x
 */
#[Some_Attribute]
class Active_Class_With_Attribute_With_Too_Long_Class_Name {} // Error.

/**
 * Class description.
 *
 * @deprecated x.x.x
 */
#[Attribute_One]
#[Attribute_Two]
class Deprecated_Class_With_Attribute_With_Too_Long_Class_Name {} // OK.

/*
 * Allow for a `_Test` suffix in classes within the unit test suite.
 */
class Three_Word_Name_Test {} // Error.

class Three_Word_Name_Test extends TestCase {} // OK.
class Three_Word_Name_Test extends WP_UnitTestCase {} // OK.

class Four_Word_Long_Name_Test extends TestCase {} // Error.

// Similarly for Double/Mock classes.
class Three_Word_Name_Double {} // Error.
class Three_Word_Name_Mock {} // Error.

class Three_Word_Name_Double extends Three_Word_Name {} // OK.
class Three_Word_Name_Mock extends Some_Class {} // OK.

/*
 * Make sure underscore prefixed names have a correct count.
 */
class __Three_Word_Name {} // OK.
class __Four_Four_Word_Name {} // Error.

/*
 * Make sure CamelCaps class names are also handled by this sniff.
 */
class ThreePartName {}
interface MyInterfaceName {}
trait SomeACRONYMName {} // Error - false positive, this will be fixed in a later iteration on this sniff.

class TooLongClassName {} // Error.
interface ThisInterfaceNameIsTooLong {} // Error.
trait TraitNameIsTooLong {} // Error.
