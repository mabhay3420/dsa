import java.util.*;
import java.util.regex.*;

public class Main {
  private static int evaluatePostfix(List<Token> tokens) {
    Stack<Integer> stack = new Stack<>();
    for (Token token : tokens) {
      TokenType type = token.getType();
      if (type == TokenType.NUMBER) {
        stack.push(Integer.parseInt(token.getContent()));
      } else {
        int op2 = stack.pop();
        int op1 = stack.pop();
        int result = 0;
        if (type == TokenType.PLUS) {
          result = op1 + op2;
        } else if (type == TokenType.MINUS) {
          result = op1 - op2;
        } else if (type == TokenType.ASTERISK) {
          result = op1 * op2;
        } else if (type == TokenType.SLASH) {
          result = op1 / op2;
        } else {
          throw new IllegalStateException("Invalid token type: " + type.name());
        }
        stack.push(result);
      }
    }
    return stack.pop();
  }

  private static List<Token> infixToPostfix(String expression) {
    List<Token> postfix = new ArrayList<>();
    Stack<Token> stack = new Stack<>();

    // Strip whitespaces.
    String[] nonWhitespaceTokens = expression.split("\\s+");
    String expr = String.join("", nonWhitespaceTokens);

    while (!expr.isEmpty()) {
      boolean matchFound = false;
      for (TokenType type : TokenType.values()) {
        Pattern p = Pattern.compile("^" + type.getPattern());
        Matcher m = p.matcher(expr);

        if (m.find()) {
          matchFound = true;
          String content = m.group(0);
          expr = expr.substring(content.length());

          Token t = new Token(content, type);

          if (type == TokenType.OPEN_PAREN) {
            stack.push(t);
          } else if (type == TokenType.CLOSE_PAREN) {
            while (stack.peek().getType() != TokenType.OPEN_PAREN) {
              postfix.add(stack.pop());
            }
            stack.pop();  // Remove "("
          } else if (type == TokenType.NUMBER) {
            postfix.add(t);
          } else if (type == TokenType.ASTERISK || type == TokenType.SLASH
              || type == TokenType.PLUS || type == TokenType.MINUS) {
            if (stack.isEmpty()) {
              stack.push(t);
            } else {
              if (t.compareTo(stack.peek()) > 0) {
                stack.push(t);
              } else {
                while (!stack.isEmpty() && t.compareTo(stack.peek()) <= 0) {
                  postfix.add(stack.pop());
                }
                stack.push(t);
              }
            }
          } else {
            throw new IllegalStateException(
                "Invalid token type: " + type.name());
          }
        }
      }

      if (!matchFound) {
        throw new IllegalArgumentException("Failed to match: '" + expr + "'");
      }
    }

    while (!stack.isEmpty()) {
      postfix.add(stack.pop());
    }

    return postfix;
  }

  private static int evaluateInfix(String expr) {
    return evaluatePostfix(infixToPostfix(expr));
  }

  public static void main(String[] args) {
    System.out.println(evaluateInfix("  7 + (2+ 3 -4 *5 + 7)- 2 "));  // -3
    System.out.println(evaluateInfix("1+(2*3-1)-2"));  // 4
    System.out.println(evaluateInfix("1+(2*(3-1))/2"));  // 3
    System.out.println(evaluateInfix("999"));  // 999
    System.out.println(evaluateInfix("1 + 10/ 2 -4"));  // 2
  }
}

enum TokenType {
  OPEN_PAREN("\\(", 0),
  PLUS("\\+", 1),
  MINUS("\\-", 1),
  ASTERISK("\\*", 2),
  SLASH("\\/", 2),
  CLOSE_PAREN("\\)", 3),
  NUMBER("[0-9]+", 4);

  private String pattern;
  private int precedence;

  private TokenType(String pattern, int precedence) {
    this.pattern = pattern;
    this.precedence = precedence;
  }

  public String getPattern() {
    return pattern;
  }

  public int getPrecedence() {
    return precedence;
  }
}

class Token implements Comparable<Token> {
  private String content;
  private TokenType type;

  public Token(String content, TokenType type) {
    assert(content != null);
    assert(type != null);
    this.content = content;
    this.type = type;
  }

  public String getContent() {
    return content;
  }

  public TokenType getType() {
    return type;
  }

  @Override
  public int compareTo(Token other) {
    assert(other != null);
    return getType().getPrecedence() - other.getType().getPrecedence();
  }

  @Override
  public String toString() {
    return String.format("Content: '%s' Type: %s", content, type.name());
  }
}
