import XCTest
import SwiftTreeSitter
import TreeSitterDdd

final class TreeSitterDddTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_ddd())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Ddd grammar")
    }
}
