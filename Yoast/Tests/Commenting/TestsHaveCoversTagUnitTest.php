<?php

namespace YoastCS\Yoast\Tests\Commenting;

use PHP_CodeSniffer\Tests\Standards\AbstractSniffUnitTest;

/**
 * Unit test class for the TestsHaveCoversTag sniff.
 *
 * @package Yoast\YoastCS
 *
 * @since   1.3.0
 *
 * @covers  YoastCS\Yoast\Sniffs\Commenting\TestsHaveCoversTagSniff
 */
class TestsHaveCoversTagUnitTest extends AbstractSniffUnitTest {

	/**
	 * Returns the lines where errors should occur.
	 *
	 * @return array <int line number> => <int number of errors>
	 */
	public function getErrorList() {
		return [
			49  => 1,
			59  => 1,
			88  => 1,
			126 => 1,
			142 => 1,
			150 => 1,
		];
	}

	/**
	 * Returns the lines where warnings should occur.
	 *
	 * @return array <int line number> => <int number of warnings>
	 */
	public function getWarningList() {
		return [];
	}
}
